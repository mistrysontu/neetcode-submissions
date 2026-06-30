class Solution {
public:
    bool canReach(vector<int>& nums, int i, int n, vector<int>& reachable) {
        if(reachable[i] != -1) return reachable[i];
        if(i == n-1 && i + nums[i] >= n-1) reachable[i] = true;
        else {
            reachable[i] = false;
            for(int j = 1; j <= nums[i]; j++) {
                reachable[i] |= canReach(nums, i+j, n, reachable);
            }
        }
        return reachable[i];
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> reachable(n, -1);
        return canReach(nums, 0, n, reachable);        
    }
};
