class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<bool>> &visited){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        visited[i][j] = true;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(auto dir: dirs){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(isValid(newi, newj, grid.size(), grid[0].size(), visited) && grid[newi][newj] == '1'){
                dfs(newi, newj, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};
