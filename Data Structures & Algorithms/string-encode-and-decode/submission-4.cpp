class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto s: strs){
            str += to_string(s.size()) + ":" + s;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != ':'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            // cout << len << endl;
            res.push_back(s.substr(j+1, len));
            i = j + len + 1;
        }
        return res;
    }
};
