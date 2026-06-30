class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = set()

        def helper(i, total, arr):
            nonlocal res
            if total == target:
                res.add(tuple(arr.copy()))
                return
            if i == len(candidates) or total > target:
                return
            arr.append(candidates[i])
            helper(i+1, total+candidates[i], arr)
            arr.pop()
            helper(i+1, total, arr)

        helper(0, 0, [])
        res = list(res)
        res = [list(i) for i in res]
        return res
