class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(0, max(nums))

        def helper(nums):
            cache = [-1] * len(nums)
            cache[0], cache[1] = nums[0], max(nums[0], nums[1])

            for i in range(2, len(nums)):
                cache[i] = max(cache[i-2] + nums[i], cache[i-1])

            return cache[len(nums)-1]

        return max(helper(nums[:-1]), helper(nums[1:]))