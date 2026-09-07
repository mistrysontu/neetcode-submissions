class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<int> dp(n, 0);

        for(int j = 0; j < n; j++) {
            dp[j] = triangle[m-1][j];                
        }
        for(int i = m-2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};