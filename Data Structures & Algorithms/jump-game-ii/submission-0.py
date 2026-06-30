class Solution:
    def jump(self, nums: List[int]) -> int:
        cache = [float('inf') for i in range(len(nums))]
        cache[-1] = 0

        for i in range(len(nums) - 2, -1, -1):
            for j in range(1, nums[i]+1):
                if i + j > len(nums) -1:
                    continue
                cache[i] = min(1+cache[i+j], cache[i])
        
        return cache[0]