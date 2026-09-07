class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i = 0; i < s.size(); i++) {
            for(auto word: wordDict) {
                if(word.size() <= n-i) {
                    if(s.substr(i, word.size()) == word) {
                        dp[i+ word.size()] = dp[i+ word.size()] || dp[i];
                    }
                }
            }
        }

        return dp[n];
    }
};
