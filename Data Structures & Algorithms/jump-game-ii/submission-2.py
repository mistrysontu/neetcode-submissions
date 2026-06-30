class Solution:
    def jump(self, nums: List[int]) -> int:
        cache = [float('inf') for i in range(len(nums))]
        cache[-1] = 0
        cnt = -1
        i = 0
        l, r = 0, 0
        while l < len(nums):
            print(l, r)
            new_max = l
            for j in range(l, r+1):

                new_max = max(new_max, j+nums[j] if j < len(nums) else len(nums)-1)

            if new_max == l and l!= len(nums)-1:
                return -1
            l = r+1
            r = new_max
            cnt += 1
        return cnt


        