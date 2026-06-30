class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:

        def dfs(i, j, val):
            if i < 0 or j < 0 or j >= len(grid[0]) or i >= len(grid) or grid[i][j] == -1:
                return
            if grid[i][j] > val + 1:
                grid[i][j] = val + 1
                dfs(i+1, j, val+1)
                dfs(i-1, j, val+1)
                dfs(i, j+1, val+1)
                dfs(i, j-1, val+1)
            
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    # start a dfs and measure distance to all the island
                    dfs(i+1, j, 0)
                    dfs(i-1, j, 0)
                    dfs(i, j+1, 0)
                    dfs(i, j-1, 0)

        # return grid