class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pList = set()
        aList = set()

        def dfs(i, j, val, xList):
            if i < 0 or j < 0 or i >= len(heights) or j >= len(heights[0]) or heights[i][j] < val or (i, j) in xList:
                return
            xList.add(tuple([i, j]))
            dfs(i+1, j, heights[i][j], xList)
            dfs(i-1, j, heights[i][j], xList)
            dfs(i, j-1, heights[i][j], xList)
            dfs(i, j+1, heights[i][j], xList)

        for j in range(len(heights[0])):
            dfs(0, j, -1, pList)
            dfs(len(heights)-1, j, -2, aList)

        for i in range(1, len(heights)):
            dfs(i, 0, -1, pList)
            dfs(len(heights)-1-i, len(heights[0])-1, -1, aList)
            print(len(heights)-1-i, len(heights[0])-1)
        
        xList = pList.intersection(aList)
        print(xList, "\n", pList, "\n", aList)
        return list(xList)