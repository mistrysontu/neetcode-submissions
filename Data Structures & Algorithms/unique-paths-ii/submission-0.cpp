class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int m = oG.size(), n = oG[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[m-1][n-1] = 1 - oG[m-1][n-1];
        for(int i = m-2; i >= 0; i--) {
            dp[i][n-1] = (1 - oG[i][n-1]) & dp[i+1][n-1];
        }

        for(int j = n-2; j >= 0; j--) {
            dp[m-1][j] = (1 - oG[m-1][j]) & dp[m-1][j+1];
        }

        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(oG[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};