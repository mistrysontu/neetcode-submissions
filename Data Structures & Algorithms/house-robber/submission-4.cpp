class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        // dp[i] = profit if we start robbery from i-th house
        int n = nums.size();
        dp.resize(n+1, 0);
        dp[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }

        return max(dp[0], dp[1]);
    }
};
