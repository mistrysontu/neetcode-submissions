class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []

        for s, e in intervals:
            if newInterval == None:
                ans.append([s,e])
                continue
            if s > newInterval[1]:
                if newInterval:
                    ans.append(newInterval)
                    newInterval = None
                    ans.append([s,e])
                    continue
            if e >= newInterval[0]:
                newInterval[0], newInterval[1] = min(newInterval[0], s), max(newInterval[1], e)
            else:
                ans.append([s, e])
        if newInterval:
            ans.append(newInterval)

        print(ans)
        return ans