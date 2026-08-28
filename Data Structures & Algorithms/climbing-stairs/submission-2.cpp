class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = dp[i-1] + dp[i-2]
        int a = 1, b = 2;
        for(int i = 3; i <= n; i++){
            int c = a + b;
            a = b;
            b = c;
        }
        if(n <= 1) return 1;
        return b;
    }
};
