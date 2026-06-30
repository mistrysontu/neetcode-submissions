class Solution {
public:
    int maxArea(vector<int>& height) {
        int curr = 0, _max = 0, left = 0, right = height.size() - 1;

        while(left < right){
            curr = (right - left) * min(height[left], height[right]);
            _max = max(_max, curr);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return _max;
    }
};
