class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while(l <= r):
            mid = l + (r-l) // 2
            if abs(r-l) <= 1:
                return min(nums[l], nums[r])
            if nums[r] > nums[mid]:
                r = mid
            else:
                l = mid
        