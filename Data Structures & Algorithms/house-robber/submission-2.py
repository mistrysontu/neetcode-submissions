class Solution:
    def rob(self, nums: List[int]) -> int:
        '''
            f(0) = nums[0]
            f(1) = nums[1]
            f(i) = f(i-2) + nums[i]
                 = f(i-1)
        '''

        cache = [0] * len(nums)
        if len(nums) <= 2: return max(max(nums), 0)

        cache[0] = nums[0]
        cache[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            cache[i] = max(cache[i-1], cache[i-2] + nums[i])
            print(cache[i])
        print(cache)
        return cache[len(nums)-1]
