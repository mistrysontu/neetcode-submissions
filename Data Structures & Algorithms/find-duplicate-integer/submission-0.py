class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for _, e in enumerate(nums):
            i = abs(e)
            if nums[i] < 0:
                return i
            nums[i] *= -1
