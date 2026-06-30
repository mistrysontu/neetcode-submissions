class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<bool>> &visited){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &val){
        visited[i][j] = true;
        val++;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(auto dir: dirs){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(isValid(newi, newj, m, n, visited) && grid[newi][newj] == 1){
                dfs(newi, newj, grid, visited, val);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int val = 0, res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    val = 0;
                    dfs(i, j, grid, visited, val);
                }
                res = max(res, val);
            }
        }
        return res;
    }
};
