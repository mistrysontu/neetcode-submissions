class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            // cout << left << " " << right << endl;
            if(nums[left] <= nums[right]) return nums[left];
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
            
        }
        return -1;
    }
};
