class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqArr = {}
        for i in range(len(nums)):
            if nums[i] not in freqArr.keys():
                freqArr[nums[i]] = 1
            else:
                freqArr[nums[i]] += 1
        freqArr = dict(sorted(freqArr.items(), key = lambda item: item[1], reverse=True))
        
        res = []
        for i in range(k):
            '''print((freqArr.keys())[i])'''
            res.append(list(freqArr.keys())[i])
        return res