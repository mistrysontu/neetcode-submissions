class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        time = 0
        q = collections.deque()           
        fresh = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    fresh += 1
                if grid[i][j] == 2:
                    q.append([i, j])
        
        directions = [[1,0], [-1, 0], [0, 1], [0, -1]]
        while q and fresh:
            for i in range(len(q)):
                top = q.popleft()

                for ii, jj in directions:
                    new_i, new_j = top[0] + ii, top[1] + jj
                    if new_i < 0 or new_j < 0 or new_i >= len(grid) or new_j >= len(grid[0]):
                        continue
                    if grid[new_i][new_j] == 1:
                        grid[new_i][new_j] = 2
                        fresh -= 1
                        q.append([new_i, new_j])

            time += 1
        
        return time if not fresh else -1
                    

                    
