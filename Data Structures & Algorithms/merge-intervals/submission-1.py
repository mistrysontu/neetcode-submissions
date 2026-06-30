class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1: return intervals
        intervals.sort(key=lambda x: x[0])
        stk = [intervals[0]]

        for i in range(1, len(intervals)):
            s, e = intervals[i][0], intervals[i][1]
            while len(stk):
                topS, topE = stk[-1][0], stk[-1][1]
                if s <= topE:
                    s = min(s, topS)
                    e = max(e, topE)
                    stk.pop()
                else:
                    break
            stk.append([s, e])
        return stk