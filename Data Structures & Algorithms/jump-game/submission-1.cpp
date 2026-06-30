class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jumpsTo(n, false);
        jumpsTo[n-1] = true;
        for(int i = n-2; i >= 0; i--){
            for(auto j = 1; j <= nums[i]; j++){
                if(jumpsTo[i+j] == true){
                    jumpsTo[i] = true;
                    break;
                }
            }
        }
        return jumpsTo[0];
    }
};
