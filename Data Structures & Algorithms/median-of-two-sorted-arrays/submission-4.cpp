class Solution {
public:

    // 1 2 3
    // 4 5 6
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n){
            swap(nums1, nums2);
            swap(m, n);
        }

        int left = 0, right = m -1;
        int total = m + n;
        int half = total / 2;

        while(true){
            int mid1 = left + (right - left) / 2;
            int mid2 = half - mid1;
            int ALeft = (mid1 - 1 >= 0) ? nums1[mid1-1] : INT_MIN;
            int BLeft = (mid2 - 1 >= 0) ? nums2[mid2-1] : INT_MIN;

            int ARight = (mid1 <= m-1) ? nums1[mid1] : INT_MAX;
            int BRight = (mid2 <= n-1) ? nums2[mid2] : INT_MAX;

            if(ALeft <= BRight && BLeft <= ARight){
                if((total & 1) == 1){
                    return min(ARight, BRight);
                }
                else{
                    return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
                }
            }
            else if(ALeft > BRight){
                right = mid1 - 1;
            }
            else{
                left = mid1 + 1;
            }
        }
        return -1;
    }
};
