"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        '''
        0, 40
        5, 10
        15, 20
        '''
        if not len(intervals): return 0
        s = 0
        res = 0
        start, end = [], []
        for i in intervals:
            start.append(i.start)
            end.append(i.end)
        i = 0
        j = 0
        start.sort()
        end.sort()
        while i < len(intervals) and j < len(intervals):
            if start[i] < end[j]:
                s += 1
                res = max(res, s)
                i += 1
            elif start[i] > end[j]:
                s -= 1
                j += 1
            else:
                i += 1
                j += 1
        return res
