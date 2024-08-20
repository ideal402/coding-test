    import heapq

    def find_and_decrement_largest_elements(n, arr):
        max_heap = [-x for x in arr]
        heapq.heapify(max_heap)
        cnt = 0
        
        while max_heap:

            largest = -heapq.heappop(max_heap)
            if largest < n:
                break

            if largest - n > 500000000:
                
                n += 30000
                cnt += 30000
                largest -= 30000
                heapq.heappush(max_heap, -largest)

            elif 1000000 < largest - n <500000000:
                n += 20000
                cnt += 20000
                largest -= 20000
                heapq.heappush(max_heap, -largest)
            else:
                n += 1
                cnt += 1
                largest -= 1
                heapq.heappush(max_heap, -largest)
            
        return cnt

    # 예시 사용법
    import sys

    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    n = arr.pop(0)
    result = find_and_decrement_largest_elements(n, arr)
    print(result)
