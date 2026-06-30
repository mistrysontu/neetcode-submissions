class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        mid = max(piles)
        left = 0
        right = mid
        res = 0
        while True:
            print(mid)
            total_time = sum([math.ceil(x / mid) for x in piles])
            if total_time <= h:
                res = mid
                right = mid
            else:
                left = mid
            
            mid = left + (right - left) // 2
            if left >= right - 1:
                break

        return res
            