class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(int i = 1;  i < intervals.size(); i++){
            if(intervals[i-1][1] >= intervals[i][0]){
                intervals[i][0] = min(intervals[i][0], intervals[i-1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                intervals[i-1][0] = -1;
                intervals[i-1][1] = -1;
            }
        }

        for(auto interval: intervals){
            if(interval[0] != -1){
                res.push_back(interval);
            }
        }

        return res;
    }
};
