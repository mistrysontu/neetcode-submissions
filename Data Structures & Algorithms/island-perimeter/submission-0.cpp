class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j] == true) return 0;
        visited[i][j] = true;
        int left = (grid[i][j] && (i-1 < 0 || grid[i-1][j] == 0)) ? 1: dfs(i-1, j, grid, visited);
        int right = (grid[i][j] && (i+1 >= m || grid[i+1][j] == 0)) ? 1: dfs(i+1, j, grid, visited);
        int top = (grid[i][j] && (j-1 < 0 || grid[i][j-1] == 0)) ? 1: dfs(i, j-1, grid, visited);
        int down = (grid[i][j] && (j+1 >= n || grid[i][j+1] == 0)) ? 1: dfs(i, j+1, grid, visited);
        // cout << left + right + top + down << endl;
        return left + right + top + down;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(visited[i][j] == false && grid[i][j]) {
                    return dfs(i, j, grid, visited);
                }
            }
        }
    }
};