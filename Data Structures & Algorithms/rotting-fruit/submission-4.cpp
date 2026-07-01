class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int steps = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int k = 0; k < qSize; k++) {
                auto front = q.front(); q.pop();
                int i = front.first, j = front.second;
                if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || grid[i][j] == 3) continue;
                if(grid[i][j] == 1) {
                    grid[i][j] = 3;
                    fresh--;
                }
                if(fresh == 0) return steps;
                q.push({i+1, j});
                q.push({i-1, j});
                q.push({i, j+1});
                q.push({i, j-1});

                if(grid[i][j] == 2) {
                    grid[i][j] = 3;
                }
            }
            steps++;
        }
        return fresh > 0 ? -1: 0;
    }
};
