class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> map(26, -1);
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            map[ch - 'a'] = i; 
        }

        vector<int> res;
        int left = 0, right = 0;
        int last = -1;
        while(right < s.size()){
            last = max(last, map[s[right]-'a']);
            // cout << s[right]-'a' << " " << map[s[right]-'a'] << " " << last << endl;
            if(last == right){
                res.push_back(right - left + 1);
                left = right + 1;
            }
            right++;
        }
        return res;
    }
};
