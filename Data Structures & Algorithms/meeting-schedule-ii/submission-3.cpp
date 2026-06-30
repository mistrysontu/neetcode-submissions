/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> arr;
        for(auto inter: intervals){
            arr.push_back({inter.start, 1});
            arr.push_back({inter.end, -1});
        }
        sort(arr.begin(), arr.end());
        int cnt = 0, res = 0;

        for(auto elem: arr){
            cnt += elem.second;
            res = max(res, cnt);
        }
        return res;
    }
};
