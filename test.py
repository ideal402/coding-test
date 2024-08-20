if len(supporters) > 3900:
        t_value = max_other_supporters//2
        # case 6
        if max_other_supporters - king_supporters > 500000000:
            while -other_supporters[0] - king_supporters > 1000000:
                test_value = 3000
                max_other = -heapq.heappop(other_supporters)  # 가장 큰 지지자 수를 가져와서 부호 반전
                max_other -= test_value
                king_supporters += test_value
                needed_supporters += test_value
                heapq.heappush(other_supporters, -max_other)  # 갱신된 값을 다시 힙에 넣음
            # test_value = max_other_supporters//2 - 10
            # max_other = -heapq.heappop(other_supporters)  # 가장 큰 지지자 수를 가져와서 부호 반전
            # max_other -= test_value
            # king_supporters += test_value
            # needed_supporters += test_value
            # if max_other < king_supporters:
            #     return 0
            # heapq.heappush(other_supporters, -max_other)  # 갱신된 값을 다시 힙에 넣음
        
        # case 4,5
        elif max_other_supporters - king_supporters > 1000000 and max_other_supporters - king_supporters < 500000000:
            while -other_supporters[0] - king_supporters > 1000000:
                max_other = -heapq.heappop(other_supporters)  # 가장 큰 지지자 수를 가져와서 부호 반전
                max_other -= 40000
                king_supporters += 40000
                needed_supporters += 40000
                heapq.heappush(other_supporters, -max_other)  # 갱신된 값을 다시 힙에 넣음


