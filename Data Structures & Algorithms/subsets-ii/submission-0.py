class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = set()
        nums.sort()
        def helper(arr, i):
            if i == len(nums):
                res.add(tuple(arr.copy()))
                return

            arr.append(nums[i])
            helper(arr, i+1)
            arr.pop()
            helper(arr, i+1)

        helper([], 0)
        res = list(res)
        res = [list(i) for i in res]
        return res
        