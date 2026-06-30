class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0], res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            curr = max(num, curr + num);
            res = max(res, curr);
        }
        return res;
    }
};
