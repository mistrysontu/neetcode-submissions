class Solution {
    int m, n;
public:

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j] == true) return 0;
        visited[i][j] = true;
        return  1 + dfs(i+1, j, grid, visited) +
                dfs(i-1, j, grid, visited) +
                dfs(i, j-1, grid, visited) + 
                dfs(i, j+1, grid, visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        m = grid.size(); n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    count = max(count, dfs(i, j, grid, visited));
                }
            }
        }
        return count;
    }
};
