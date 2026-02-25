import requests
import xml.etree.ElementTree as ET
import csv
import h3
import time

API_KEY = "53554a774e69646531394758435470"
INPUT_CSV = "seoul_spots.csv"
OUTPUT_CSV = "road_link_info.csv"

def fetch_and_save_traffic_data_by_area():
    area_names = []
    
    # 1. 입력 CSV 파일에서 AREA_NM 추출
    try:
        with open(INPUT_CSV, mode='r', encoding='utf-8-sig') as infile:
            reader = csv.DictReader(infile)
            for row in reader:
                # AREA_NM 컬럼이 존재하는지 확인 후 리스트에 추가
                if 'AREA_NM' in row and row['AREA_NM'].strip():
                    area_names.append(row['AREA_NM'].strip())
    except FileNotFoundError:
        print(f"Error: {INPUT_CSV} 파일을 찾을 수 없습니다. 파일 경로를 확인해주세요.")
        return
    except Exception as e:
        print(f"Error: 입력 CSV 파일 읽기 실패 - {e}")
        return

    if not area_names:
        print("경고: 추출된 지역명이 없습니다. AREA_NM 컬럼을 확인해주세요.")
        return

    print(f"총 {len(area_names)}개의 지역에 대해 API 요청을 시작합니다.")

    # 2. 출력 CSV 파일 오픈 (전체 데이터를 단일 파일로 병합 작성)
    with open(OUTPUT_CSV, mode='w', encoding='utf-8-sig', newline='') as outfile:
        writer = csv.writer(outfile)
        
        # CSV 헤더 작성
        writer.writerow([
            'link_id', 'road_nm', 'start_nd_cd', 'start_nd_nm', 
            'start_lng', 'start_lat', 'end_nd_cd', 'end_nd_nm', 
            'end_lng', 'end_lat', 'dist', 'xy_list', 'h3_index'
        ])
        
        # 3. 추출한 지역명을 순회하며 API HTTP GET Request 수행
        for idx, area in enumerate(area_names, start=1):
            API_URL = f"http://openapi.seoul.go.kr:8088/{API_KEY}/xml/citydata/1/5/{area}"
            print(f"[{idx}/{len(area_names)}] {area} 지역 요청 중...")
            
            try:
                response = requests.get(API_URL, timeout=10)
                response.raise_for_status() 
                
                root = ET.fromstring(response.content)
                status_list = root.findall('.//ROAD_TRAFFIC_STTS')
                
                if not status_list:
                    print(f"  -> {area}: 응답 데이터에 ROAD_TRAFFIC_STTS 항목 없음")
                    continue
                    
                for status in status_list:
                    link_id = status.findtext('LINK_ID')
                    road_nm = status.findtext('ROAD_NM')
                    start_nd_cd = status.findtext('START_ND_CD')
                    start_nd_nm = status.findtext('START_ND_NM')
                    
                    start_xy_str = status.findtext('START_ND_XY')
                    if start_xy_str and '_' in start_xy_str:
                        start_lng_str, start_lat_str = start_xy_str.split('_')
                        start_lng = float(start_lng_str)
                        start_lat = float(start_lat_str)
                    else:
                        start_lng, start_lat = None, None
                        
                    end_nd_cd = status.findtext('END_ND_CD')
                    end_nd_nm = status.findtext('END_ND_NM')
                    
                    end_xy_str = status.findtext('END_ND_XY')
                    if end_xy_str and '_' in end_xy_str:
                        end_lng_str, end_lat_str = end_xy_str.split('_')
                        end_lng = float(end_lng_str)
                        end_lat = float(end_lat_str)
                    else:
                        end_lng, end_lat = None, None
                        
                    dist_str = status.findtext('DIST')
                    dist = float(dist_str) if dist_str else None
                    
                    xy_list = status.findtext('XYLIST')
                    
                    if start_lat and start_lng:
                        h3_index = h3.latlng_to_cell(start_lat, start_lng, 9)
                    else:
                        h3_index = None
                        
                    # Row 버퍼에 기록
                    writer.writerow([
                        link_id, road_nm, start_nd_cd, start_nd_nm,
                        start_lng, start_lat, end_nd_cd, end_nd_nm,
                        end_lng, end_lat, dist, xy_list, h3_index
                    ])
                print(f"  -> {area}: {len(status_list)}건 저장 완료")
                
            except requests.exceptions.RequestException as e:
                print(f"  -> {area} API Network Error: {e}")
            except ET.ParseError as e:
                print(f"  -> {area} XML Parse Error: {e}")
            except Exception as e:
                print(f"  -> {area} Unexpected Error: {e}")

            # 서버 부하 방지 및 Rate Limit 대응을 위한 지연(Delay)
            time.sleep(0.5) 

    print(f"모든 작업이 완료되었습니다. 결과가 {OUTPUT_CSV}에 저장되었습니다.")

if __name__ == "__main__":
    fetch_and_save_traffic_data_by_area()