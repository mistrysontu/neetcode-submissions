class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxList(n, 1), minList(n, 1);
        maxList[0] = nums[0];
        minList[0] = nums[0];
        int val = nums[0];
        for(int i = 1; i < n; i++) {
            maxList[i] = max(nums[i], max(maxList[i-1] * nums[i], minList[i-1] * nums[i]));
            minList[i] = min(nums[i], min(maxList[i-1] * nums[i], minList[i-1] * nums[i]));
            val = max(val, maxList[i]);
        }
        return val;
    }
};
