class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, int> umap;

        for(int elem: nums){
            if(umap.find(elem) == umap.end()){
                // cout << elem << " is not present" << endl;
                umap[elem] = 1;
            }
            else{
                // cout << elem << " is present." << endl;
                return true;
            }
        }
        return false;
    }
};
