class Solution {
public:
    string helper(string s, int i, int j){
        if(i < 0 && j >= s.size()) return s;
        if(i < 0) return s.substr(0, j);
        if(j >= s.size()) return s.substr(i+1, s.size() - i);
        if(s[i] == s[j]){
            return helper(s, i-1, j+1);
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); i++){
            string temp = helper(s, i, i);
            if(temp.size() > res.size()) res = temp;
            temp = helper(s, i, i+1);
            if(temp.size() > res.size()) res = temp;
        }
        return res;
    }
};
