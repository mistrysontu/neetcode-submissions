// Good: condition check, why add (either or logic), instead of multiplication (both at the same time: eg: 3 pants and 4 shirts, they can be paired independant)

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> map(n+1, 0); // need to be n+1, as 10 is valid sequence but we'll miss it as i+1 for idx#n-1 doesn't exist.
        map[n] = 1;

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0') {
                map[i] = 0;
                continue;
            }
            map[i] = map[i+1];
            if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
                map[i] += map[i+2];
            }
        }
        return map[0];
    }
};
/*
1112
1 1 1  2
1 1 12
1 11 2
11 1 2
11 12

*/