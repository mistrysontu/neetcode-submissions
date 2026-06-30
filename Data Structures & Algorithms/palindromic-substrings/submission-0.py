class Solution:
    def countSubstrings(self, s: str) -> int:
        '''
        aa
        '''
        cnt = 0
        def helper(i, j):
            nonlocal cnt
            if i < 0 or j >= len(s):
                return 
            if s[i] == s[j]:
                cnt += 1
                helper(i-1, j+1)

        for i in range(len(s)):
            helper(i, i)
            helper(i, i+1)
        return cnt