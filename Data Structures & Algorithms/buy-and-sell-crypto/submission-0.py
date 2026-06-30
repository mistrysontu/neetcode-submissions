class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 4 8 3
        stk = 101
        profit = 0
        for p in prices:
            if stk > p:
                stk = p
            else:
                profit = max(profit, p - stk)
        return profit
