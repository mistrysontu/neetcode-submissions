class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> umap;
        for(auto i: intervals){
            int n = (i[1] - i[0] + 1);
            for(int j = i[0]; j <= i[1]; j++){
                if(umap.find(j) == umap.end()){
                    umap[j] = n;
                }
                else{
                    umap[j] = min(umap[j], n);
                }
            }
        }
        vector<int> res;
        for(auto q: queries){
            if(umap.find(q) == umap.end()){
                res.push_back(-1);
            }
            else res.push_back(umap[q]);
        }
        return res;
    }
};
