class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >=n) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    cnt = -1;
                }
            }
        }

        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
                for(auto dir: dirs){
                    int newi = curr.first + dir.first;
                    int newj = curr.second + dir.second;
                    if(isValid(newi, newj, m, n) && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({newi, newj});
                    }
                }
            }
            cnt++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};
