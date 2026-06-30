class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        cache = {}
        def helper(n):
            nonlocal cache
            if n < 0:
                return float('inf')
            if n == 0:
                return 0
            
            if n in cache:
                return cache[n]

            x = float('inf')
            for i in coins:
                x = min(x, 1 + helper(n-i))
            print(n, x)
            cache[n] = x
            return x
        res = helper(amount)
        return res if res != float('inf') else -1