class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for(auto str: strs) {
            auto str_cpy = str;
            sort(str_cpy.begin(), str_cpy.end());
            umap[str_cpy].push_back(str);
        }

        for(auto elem: umap) {
            res.push_back(elem.second);
        }
        return res;
    }
};
