class Solution:
    def __init__(self):
        self.arr = []
    def getPermute(self, nums, left, right):
        if left == right:
            self.arr.append(nums.copy())
            return
        else:
            for i in range(left, right):
                nums[i], nums[left] = nums[left], nums[i]
                self.getPermute(nums, left+1, right)
                nums[i], nums[left] = nums[left], nums[i]

    def permute(self, nums: List[int]) -> List[List[int]]:
        left, right = 0, len(nums) 
        self.getPermute(nums, left, right)
        return self.arr
        
