class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def helper(nums, i, arr):
            nonlocal res
            print(arr, i)
            if sum(arr) == target:
                res.append(arr.copy())
                return
            if i == len(nums):
                return
            if sum(arr) > target:
                return
            arr.append(nums[i])
            helper(nums, i, arr)
            # helper(nums, i+1, arr)
            arr.pop()
            helper(nums, i+1, arr)

        helper(nums, 0, [])

        return res
