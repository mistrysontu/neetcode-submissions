class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        elemSet = {}
        for pos, n in enumerate(nums):
            if target - n in elemSet:
                return [elemSet[target - n], pos]
            elemSet[n] = pos
                
