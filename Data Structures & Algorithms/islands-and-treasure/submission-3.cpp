class Solution {
public:
    int m, n;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int steps = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int k = 0; k < qSize; k++) {
                auto top = q.front(); q.pop();
                int i = top.first, j = top.second;
                if(i < 0 || j < 0|| i >= m || j >= n || grid[i][j] == -1 ) continue;
                if(grid[i][j] != 0 && grid[i][j] > steps)
                    grid[i][j] = steps;
                if(grid[i][j] == 0 || grid[i][j] >= steps){
                    q.push({i+1, j});
                    q.push({i-1, j});
                    q.push({i, j+1});
                    q.push({i, j-1});
                }

            }
            steps++;
        }
    }
};
