class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++){
            if(umap.count(target - nums[i]) == 0){
                umap[nums[i]] = i;
            }
            else{
                return {umap[target - nums[i]], i};
            }
        }
        return {-1, -1};
    }
};
