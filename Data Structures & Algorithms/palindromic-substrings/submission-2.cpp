class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> map(n, vector<bool>(n, false));
        int cnt = 0;

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if((s[i] == s[j]) && ((j-i < 3) || (map[i+1][j-1]))) {
                    map[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
