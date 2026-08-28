class Solution {
public:

    vector<int> dp;

    void getCost(int end, int start, vector<int>& cost) {
        for(int i = end-1; i >= start; i--) {
            dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        }
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1, 0);
        dp[n-1] = cost[n-1];
        dp[n] = 0;
        getCost(n-1, 0, cost); 
        return min(dp[0], dp[1]);
    }
};
