class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        res = []
        a, b, c = target[:3]

        for p, q, r in triplets:
            if p > a or q > b or r > c:
                continue
            if p == a:
                res.append(True)
            if q == b:
                res.append(True)
            if r == c:
                res.append(True)
        return len(res) >= 3