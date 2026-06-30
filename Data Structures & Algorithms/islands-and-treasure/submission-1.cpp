class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<bool>> &visited){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return false;
        return true;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // multi source bfs
        int dist = 1;
        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto qtop = q.front();
                q.pop();
                for(auto dir: dirs){
                    int newi = qtop.first + dir[0];
                    int newj = qtop.second + dir[1];
                    if(isValid(newi, newj, m, n, visited)){
                        if(grid[newi][newj] == 0 || grid[newi][newj] == -1) continue;
                        q.push({newi, newj});
                        visited[newi][newj] = true;
                        grid[newi][newj] = dist;
                    }
                }
            }
            dist++;
        }
    }
};
