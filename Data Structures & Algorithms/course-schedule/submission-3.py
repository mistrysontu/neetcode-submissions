class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for i in range(numCourses)]
        for i in prerequisites:
            graph[i[1]].append(i[0])
        gVisisted = [0]*numCourses

        for pos, elem in enumerate(graph):
            print(pos)
            print(elem)
            
            q = [pos]
            cnt = 10
            visited = [0]*numCourses
            while(len(q)):
                # cnt -= 1
                # if cnt == 0:
                #     return False
                top = q.pop()
                visited[top] = 1
                # if gVisisted[top]:
                #     pass
                if(len(graph[top]) == 0):
                    visited[top] = 0
                for pos1,i in enumerate(graph[top]):
                    print("{0}, {1}".format(i, visited[i]))
                    q.append(i)
                    gVisisted[i] = 1
                    if (visited[i]):
                        return False
                    if pos1 == len(graph[top])-1:
                        visited[i] = 0
                # visited[top] = 0         

        return True
