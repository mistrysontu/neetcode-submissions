class Solution {
public:
    void helper(string s, int i, int j, int& cnt){
        if(i < 0 || j >= s.size()) return;
        if(s[i] == s[j]){
            cnt++;
            helper(s, i-1, j+1, cnt);
        }
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            helper(s, i, i, cnt);
            helper(s, i, i+1, cnt);
        }
        return cnt;
    }
};
