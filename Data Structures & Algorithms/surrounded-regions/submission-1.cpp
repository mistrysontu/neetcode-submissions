class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<bool>> &visited){
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return false;
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = true;
                board[i][0] = 'Y';
            }

            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                visited[i][n-1] = true;
                board[i][n-1]= 'Y';

            }
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                visited[0][j] = true;
                board[0][j] = 'Y';
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                visited[m-1][j] = true;
                board[m-1][j] = 'Y';
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(q.size()){
            auto curr = q.front();
            q.pop();

            for(auto dir: dirs){
                int newi = curr.first + dir[0];
                int newj = curr.second + dir[1];

                if(isValid(newi, newj, m, n, visited) && board[newi][newj] == 'O'){
                    board[newi][newj] = 'Y';
                    visited[newi][newj] = true;
                    q.push({newi, newj});
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
