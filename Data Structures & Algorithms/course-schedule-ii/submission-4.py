class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        '''
            # 2 -> 1 -> 0 -> 2
            2 : [1]
            1 : [0]
            0 : [1] 
            2 -> 1 <==> 0
        '''
        graph = {}
        res = {}
        for i, j in prerequisites:
            # if graph[i]:
            #     graph[i].append(j)
            # else:
            #     graph[i] = [j]
            if j in graph.keys():
                graph[j].append(i)
            else:
                graph[j] = [i]
        
        visited = {}

        def hasCycle(node, path):
            nonlocal visited, graph, res
            print(node, path)
            # iterate over all the neighbours of current node and do DFS on them
            if node not in graph:
                path[node] = False
                print('bye')
                return False
            for i in graph[node]:
                # check we alredy seen this i node before in the path
                if i in visited and i not in path:
                    continue
                if i in path and path[i]:
                    print('i ', i, path)
                    return True
                # i is part of the current path
                path[i] = True
                visited[i] = True
                if hasCycle(i, path):
                    return True
            res[node] = None
                
            path[i] = False
            return False

        for k in graph.keys():
            print(graph)
            currPath = {}
            if k not in visited:
                visited[k] = True
                currPath[k] = True
                if (hasCycle(k, currPath)):
                    return []
                res[k] = None
        
        n = len(list(res.keys()))
        for i in range(numCourses):
            if i not in res:
                res[i] = None
        res = list(res.keys())
        res[:n] = res[:n][::-1]
        return res

