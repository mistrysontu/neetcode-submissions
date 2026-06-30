class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodTillIdx(n, 1), prodAfterIdx(n, 1), res(n,0);

        for(int i = 1; i < n; i++){
            prodTillIdx[i] = prodTillIdx[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--){
            prodAfterIdx[i] = prodAfterIdx[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++){
            res[i] = prodTillIdx[i] * prodAfterIdx[i];
        }

        return res;
    }
};
