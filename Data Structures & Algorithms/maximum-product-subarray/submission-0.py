class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        curMax, curMin = 1, 1
        for n in nums:
            tmp = n * curMax
            curMax = max(n, n*curMin, n*curMax)
            curMin = min(n, n*curMin, tmp)
            res = max(res, curMax)

        return res