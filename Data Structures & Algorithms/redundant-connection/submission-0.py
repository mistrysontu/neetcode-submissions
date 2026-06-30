class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = [i for i in range(len(edges)+1)]

        def find(x):
            nonlocal parent
            p = parent[x]
            while p != parent[p]:
                p = parent[p]
            return p

        def union(x, y):
            nonlocal parent
            parent_x = find(x)
            parent_y = find(y)
            if parent_x == parent_y:
                return False # Unsucessful union operation
            parent[parent_x] = parent_y
            return True # sucess 

        for i, j in edges:
            if not union(i,j):
                return [i, j]
        return []