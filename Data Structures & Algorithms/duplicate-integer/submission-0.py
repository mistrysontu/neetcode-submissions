class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        elem = dict()
        for i in nums:
            if i in elem.keys():
                return True
            elem[i] = 1
        return False