class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stk = []
        res = [0 for i in range(len(temperatures))]
        for i, t in enumerate(temperatures):
            if not len(stk):
                stk.append((i, t))
            elif stk[-1][1] > t:
                stk.append((i, t))
            else:
                while len(stk):
                    if stk[-1][1] < t:
                        pi, pt = stk.pop()
                        res[pi] = (i - pi)
                    else:
                        stk.append((i, t))
                        break
                if not(len(stk)):
                    stk.append((i,t))

        return res
