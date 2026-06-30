class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        '''
            0 -> 1 -> 2 -> 3 -> 1
            (a, c)
               a    b
              / \  / \
             c   d    e
               a  b   c  d  e
             a -1 -1  0  0 -1
             b -1 -1 -1  0  0
             c -1 -1 -1 -1 -1
             d -1 -1 -1 -1 -1
             e -1 -1 -1 -1 -1

        '''
        if len(edges) <= 0:
            return True
        # Create an adjacency list
        graph = {}
        for i, j in edges:
            if i in graph:
                if j in graph[i]: # if cycle in b/w two adjacent nodes
                    return False
                graph[i].append(j)
            else:
                graph[i] = [j]
            
            if j in graph:
                if i in graph[j]: # if cycle in b/w two adjacent nodes
                    return False
                graph[j].append(i)
            else:
                graph[j] = [i]

        visited = [False for i in graph.keys()]
        
        # just check if all nodes are connected or not and if there is no cycle

        def dfs(node, prev):
            nonlocal graph, visited
            for neighbour in graph[node]:
                if neighbour == prev:
                    continue
                if visited[neighbour] : #cycle
                    return False
                if not visited[neighbour]:
                    visited[neighbour] = True
                    if not (dfs(neighbour, node)):
                        return False
            return True

        visited[0] = True
        if not dfs(0, None):
            return False

        return False if False in visited else True
        
