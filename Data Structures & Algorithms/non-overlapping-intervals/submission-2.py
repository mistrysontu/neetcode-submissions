class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) <= 1: return 0
        intervals.sort(key=lambda x: x[0])
        prevEnd = intervals[0][1]
        cnt = 0
        for s, e in intervals[1:]:
            if s >= prevEnd:
                prevEnd = e
            else:
                cnt += 1
                prevEnd = min(prevEnd, e)
        return cnt