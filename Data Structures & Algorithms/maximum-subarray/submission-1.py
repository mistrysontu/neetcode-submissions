class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res, res_a = nums[0], nums[0]
        for i, num in enumerate(nums):
            if i == 0:
                continue
            if res_a + num >= num:
                res_a = res_a + num
            else:
                res_a = num
            res = max(res, res_a)
            # print(res_a)
        return res