class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> gain(n, 0);
        if(n == 1) return nums[0];
        gain[n-1] = nums[n-1];
        gain[n-2] = max(nums[n-1], nums[n-2]);

        for(int i = n-3; i >= 0; i--){
            gain[i] = max(nums[i] + gain[i+2], gain[i+1]);
        }
        return gain[0];
    }
};
