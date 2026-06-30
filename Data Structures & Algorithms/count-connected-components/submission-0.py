class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parents = [i for i in range(n)]
        def union(a, b):
            nonlocal parents
            pa = find(a)
            pb = find(b)
            if pa != pb:
                parents[pa] = pb

        def find(a):
            nonlocal parents
            p = parents[a]
            while p != parents[p]:
                parents[p] = parents[parents[p]]
                p = parents[p]
            return p

        for i, j in edges:
            union(i, j)
        print(parents)

        res = set()

        for i in parents:
            res.add(find(i))

        return len(res)
