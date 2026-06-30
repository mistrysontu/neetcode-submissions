class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> stk;
        for(auto i: intervals){
            int s = i[0], e = i[1];
            if(!stk.size()){
                stk.push(i);
                continue;
            }
            while(stk.size()){
                int cs = stk.top()[0], ce = stk.top()[1];
                if(ce > s){
                    res++;
                    cout << s << " " << e << " " << cs << " " << ce << endl;
                        stk.pop();
                    if(e > ce){
                        // stk.push({s, e});
                        s = cs, e = ce;
                    }
                }
                else break;
            }

            stk.push({s, e});
        }
        return res;
    }
};
