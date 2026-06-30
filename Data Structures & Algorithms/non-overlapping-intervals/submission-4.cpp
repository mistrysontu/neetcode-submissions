class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        if(intervals.size() == 0) return 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= prevEnd){
                prevEnd = intervals[i][1];
            }
            else{
                prevEnd = min(prevEnd, intervals[i][1]);
                cnt++;
            }
        }
        return cnt;
    }
};
