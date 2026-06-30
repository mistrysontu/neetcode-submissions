class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2: return n
        step1, step2 = 1, 2
        ways = 2
        for i in range(3, n+1):
            ways = step1 + step2
            step1, step2 = step2, ways
        return ways