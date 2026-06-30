class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0, right = 1;
        int prev = 0;
        int n = arr.size();
        int res = 1;
        while(right < n) {
            if(arr[right-1] < arr[right] && prev != -1) {
                prev = -1;
                right++;
                res = max(res, right-left);
            }
            else if(arr[right-1] > arr[right] && prev != 1) {
                prev = 1;
                res = max(res, right-left+1);
                right++;
            }
            else {
                if(arr[right-1] == arr[right]) {
                    right++;
                }
                left = right - 1;
                prev = 0;
            }
        }
        return res;
    }
};