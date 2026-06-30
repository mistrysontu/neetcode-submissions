class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # try adding (
        # try adding )
        ret = []

        def helper(s, n, o, c):
            nonlocal ret
            if c == n:
                ret.append(s)
            if o < n:
                helper(s + '(', n, o+1, c)
            if c < o:
                helper(s+ ')', n, o, c+1)

        helper('', n, 0, 0)
        return ret
