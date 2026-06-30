class Solution:
    def __init__(self):
        self.arr = set()
    def helper(self, nums, i):
        if i == len(nums):
            self.arr.add(tuple(nums))
            return
        self.helper(nums[0:i] + nums[i+1:], 0)
        self.helper(nums, i+1)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.helper(nums, 0)
        arr = [list(x) for x in self.arr]
        return arr


        