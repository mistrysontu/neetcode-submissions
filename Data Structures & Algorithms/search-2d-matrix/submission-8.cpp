class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[mid][n-1] == target) return true;
            else if(matrix[mid][n-1] > target){
                row = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        if(row == -1) return false;
        left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }
};
