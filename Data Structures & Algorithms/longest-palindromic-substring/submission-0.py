class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''
            abccba
        '''
        def helper(i, j, n, res):
            print(res)
            if i < 0 or j >= len(s):
                return res
            if s[i] == s[j]:
                n = (j-i+1)
                if n > len(res):
                    res = s[i:j+1]
                return helper(i-1, j+1, n, res)
            return res
        
        res = ""
        for i in range(len(s)):
            odd = helper(i, i, 0, "")
            even = helper(i, i+1, 0, "")

            if len(odd) > len(res):
                res = odd
            if len(even) > len(res): res = even
        
        return res

                