class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        cache = {}
        for i, e in enumerate(s):
            cache[e] = i
        x, y = 0, -1
        res = []

        for i, e in enumerate(s):
            x = max(x, cache[e])
            if i == x:
                res.append(x - y )
                y = x

        return res