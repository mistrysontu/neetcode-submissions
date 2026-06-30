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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        stack<Interval> stk;
        for(auto i: intervals){
            if(!stk.size()){
                stk.push(i);
                continue;
            }
            int s = i.start, e = i.end;
            Interval j = stk.top();
            int ss = j.start, se = j.end;
            if(s < se) return false;
            stk.push(i);
        }
        return true;
    }
};
