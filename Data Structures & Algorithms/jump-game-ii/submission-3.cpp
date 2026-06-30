class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumpNeeded(n, INT_MAX);
        jumpNeeded[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            for(int j = 1; j <= nums[i]; j++){
                if(jumpNeeded[i+j] != INT_MAX){
                    jumpNeeded[i] = min(jumpNeeded[i], jumpNeeded[i+j] + 1);
                }
            }
        }
        return jumpNeeded[0];
    }
};
