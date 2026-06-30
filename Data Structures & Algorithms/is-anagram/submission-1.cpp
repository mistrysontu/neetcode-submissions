class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for(auto ch: s){
            umap[ch]++;
        }
        for(auto ch: t){
            umap[ch]--;
        }

        for(auto elem: umap){
            if(elem.second != 0) return false;
        }
        return true;
    }
};
