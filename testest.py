import csv

INPUT_CSV = "road_link_info.csv"
OUTPUT_CSV = "road_link_info_cleaned.csv"

def remove_empty_rows():
    try:
        # 1. 파일 입력 스트림(Input Stream) 개방
        with open(INPUT_CSV, mode='r', encoding='utf-8-sig') as infile:
            reader = csv.reader(infile)
            
            # 2. 리스트 컴프리헨션과 내장 함수 any()를 활용한 필터링 로직
            # 각 행(row)을 순회하며, 행 내부의 각 셀(cell) 값에서 공백을 제거(strip)한 후
            # True로 평가되는(유효한 문자열이 존재하는) 셀이 하나라도 포함된 행만 추출합니다.
            cleaned_rows = [row for row in reader if any(cell.strip() for cell in row)]
            
        # 3. 파일 출력 스트림(Output Stream) 개방 및 일괄 쓰기
        with open(OUTPUT_CSV, mode='w', encoding='utf-8-sig', newline='') as outfile:
            writer = csv.writer(outfile)
            writer.writerows(cleaned_rows)
            
        # len() 내장 함수를 통해 헤더를 포함한 최종 유효 행의 개수를 산출합니다.
        print(f"정제 완료: 총 {len(cleaned_rows)}개의 유효한 행이 {OUTPUT_CSV}에 저장되었습니다.")
        
    except FileNotFoundError:
        print(f"오류: {INPUT_CSV} 파일을 찾을 수 없습니다.")
    except Exception as e:
        print(f"파일 처리 중 예외가 발생했습니다: {e}")

if __name__ == "__main__":
    remove_empty_rows()