class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target+1, 0);

        for(auto stone: stones) {
            for(int i = target; i >= stone; i--) {
                dp[i] = max(dp[i], dp[i-stone] + stone);
            }
        }
        return sum - (dp[target] * 2);
    }
};