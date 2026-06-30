class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = {i:1 for i in nums}
        res = 0
        for i in nums:
            ln = 1
            if i-1 in numSet.keys():
                continue
            while(i+1 in numSet.keys()):
                ln += 1
                i += 1
            res = max(res, ln)

        return res 
            
