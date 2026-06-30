class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        graph = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        res = []
        def permute(s, i):
            nonlocal res
            if i == len(digits):
                res.append(s)
                return
            for j in range(len(graph[digits[i]])):
                s += graph[digits[i]][j]
                permute(s, i+1)
                s = s[:-1]
        if digits == "":
            return res
        permute("", 0)
        return res