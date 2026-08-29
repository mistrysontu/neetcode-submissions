class Solution {
public:
    int rob(vector<int>& nums, int startIdx, int endIdx) {
        int n = nums.size();
        if(startIdx == endIdx) return nums[startIdx];
        vector<int> dp(n, 0);
        dp[endIdx] = nums[endIdx];
        dp[endIdx-1] = max(nums[endIdx], nums[endIdx-1]);

        for(int i = endIdx-2; i >= startIdx; i--) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[startIdx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    
    }
};
