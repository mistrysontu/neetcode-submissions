class Solution {
public:
    bool isAlphaNumaric(char c){
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(!isAlphaNumaric(s[i])) i++;
            while(!isAlphaNumaric(s[j])) j--;
            if(i >= j) return true;
            // cout << tolower('A') ;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
