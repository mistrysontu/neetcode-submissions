class Solution:
    def isValid(self, s: str) -> bool:
        dic = {')': '(', '}': '{', ']': '['}
        stk = []
        for i in s:
            if i in dic.values():
                stk.append(i)
            elif i in dic.keys():
                if not len(stk):
                    return False
                elif stk[-1] != dic[i]:
                    return False
                else:
                    stk.pop()

        return not len(stk)
                