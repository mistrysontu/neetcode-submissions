class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0), sufix(n, 0);
        prefix[0] = height[0];
        sufix[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            prefix[i] = max(height[i], prefix[i-1]);
        }

        for(int j = n-2; j >= 0; j--){
            sufix[j] = max(height[j], sufix[j+1]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(prefix[i], sufix[i]) - height[i];
        }

        return res;
    }
};
