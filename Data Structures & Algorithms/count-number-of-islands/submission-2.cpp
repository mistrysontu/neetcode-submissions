class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i+1, j, grid, visited);
        dfs(i-1, j, grid, visited);
        dfs(i, j-1, grid, visited);
        dfs(i, j+1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
