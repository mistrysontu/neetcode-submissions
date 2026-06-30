class Solution:
    def checkValidString(self, s: str) -> bool:
        cache = {}
        def helper(i, cnt):
            nonlocal cache
            if i >= len(s): return cnt == 0
            if cnt < 0: return False

            if s[i] == '(':
                if not (i+1, cnt+1) in cache:
                    cache[(i+1, cnt+1)] = helper(i+1, cnt+1)
                return cache[(i+1, cnt+1)]
            elif s[i] == ')':
                if not (i+1, cnt-1) in cache:
                    cache[(i+1, cnt-1)] = helper(i+1, cnt-1)
                return cache[(i+1, cnt-1)]
            else:
                if not (i+1, cnt-1) in cache:
                    cache[(i+1, cnt-1)] = helper(i+1, cnt-1)
                if not (i+1, cnt+1) in cache:
                    cache[(i+1, cnt+1)] = helper(i+1, cnt+1)
                if not (i+1, cnt) in cache:
                    cache[(i+1, cnt)] = helper(i+1, cnt)
                return cache[(i+1, cnt)] or cache[(i+1, cnt+1)] or cache[(i+1, cnt-1)] 
        
        return helper(0, 0)