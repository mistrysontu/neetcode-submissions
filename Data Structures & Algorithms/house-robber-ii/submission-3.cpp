class Solution {
public:
    int robHelper(vector<int> &nums, int left, int right){
        int n = right - left ;
        if(n == 1) return nums[left];
        vector<int> gain(n, 0);
        gain[right - 1] = nums[right - 1];
        gain[right - 2] = max(nums[right - 1], nums[right - 2]);

        for(int i = right - 3; i >= left; i--){
            gain[i] = max(nums[i] + gain[i+2], gain[i+1]);
        }
        return gain[left];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robHelper(nums, 0, n-1), robHelper(nums, 1, n));
    }
};
