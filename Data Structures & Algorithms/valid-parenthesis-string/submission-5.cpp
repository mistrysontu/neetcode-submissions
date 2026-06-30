class Solution {
public:
    vector<vector<int>> lookup;
    bool helper(int i, int cnt, string s){
        if(i >= s.size()) return cnt == 0;
        if(cnt < 0) return false; // more closing bracket than opening one.

        if(s[i] == '('){
            if(lookup[i+1][cnt+1] == -1) lookup[i+1][cnt+1] = helper(i+1, cnt+1, s);
            return lookup[i+1][cnt+1];
            
        }
        else if(s[i] == ')'){
            if(lookup[i+1][cnt-1] == -1) lookup[i+1][cnt-1] = helper(i+1, cnt-1, s);
            return lookup[i+1][cnt-1];
            
        }

        if(lookup[i+1][cnt+1] == -1) lookup[i+1][cnt+1] = helper(i+1, cnt+1, s);
        if(lookup[i+1][cnt-1] == -1) lookup[i+1][cnt-1] = helper(i+1, cnt-1, s);
        if(lookup[i+1][cnt] == -1) lookup[i+1][cnt] = helper(i+1, cnt, s);
        return lookup[i+1][cnt+1] || lookup[i+1][cnt-1] || lookup[i+1][cnt];
    }
    bool checkValidString(string s) {
        int n = s.size() + 1;
        lookup.resize(n, vector<int> (n, -1));
        return helper(0, 0, s);
    }
};
