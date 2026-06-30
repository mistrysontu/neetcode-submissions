class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        resultArr = list()
        nums.sort()
        firstIdx = 0
        while (firstIdx < len(nums) - 2):
            if nums[firstIdx] > 0:
                break
            if firstIdx > 0 and nums[firstIdx] == nums[firstIdx - 1]:
                firstIdx += 1
                continue
            secondIdx = firstIdx + 1
            thirdIdx = len(nums) - 1
            while (secondIdx < thirdIdx):
                sum = nums[firstIdx] + nums[secondIdx] + nums[thirdIdx]
                if sum == 0:
                    resultArr.append([nums[firstIdx], nums[secondIdx], nums[thirdIdx]])
                    secondIdx, thirdIdx = secondIdx + 1, thirdIdx -1
                    while(thirdIdx > secondIdx and nums[thirdIdx] == nums[thirdIdx+1]):
                        thirdIdx -= 1
                elif sum > 0:
                    thirdIdx -= 1
                else:
                    secondIdx += 1
            firstIdx += 1
        return resultArr
        
        

        