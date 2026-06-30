class Solution {
    int m, n;
public:
    bool dfs(int u, int v, int idx, vector<vector<char>>& board, string word, vector<vector<bool>>& visited) {
        if(idx == word.size()) return true;
        if(u < 0 || u >= m || v < 0 || v >= n || visited[u][v] || board[u][v] != word[idx]) return false;
        visited[u][v] = true;

        bool res = dfs(u+1, v, idx+1, board, word, visited) 
                 || dfs(u-1, v, idx+1, board, word, visited)
                 || dfs(u, v-1, idx+1, board, word, visited)
                 || dfs(u, v+1, idx+1, board, word, visited);

        visited[u][v] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 0, board, word, visited)) return true;
                }
            }
        }
        return false;

    }
};
