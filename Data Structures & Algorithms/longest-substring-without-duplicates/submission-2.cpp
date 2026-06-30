class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> umap(256, 0);
        int res = 0;
        int left = 0, right = 0;

        for(right = 0; right < s.size(); right++){
            if(umap[s[right]] == 0){
                umap[s[right]] = 1;
            }
            else{
                while(umap[s[right]] != 0){
                    umap[s[left]]--;
                    left++;
                }
                umap[s[right]] = 1;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};
