class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> stk;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(auto i: intervals){
            int s = i[0], e = i[1];
            if(!stk.size()){
                stk.push(i);
                continue;
            }
            while(stk.size()){
                vector<int> curr = stk.top();
                int cs = curr[0], ce = curr[1];
                if(s <= ce){
                    s = min(s, cs);
                    e = max(e, ce);
                    stk.pop();
                }
                else{
                    break;
                }
            }
            stk.push({s, e});
        }
        while(stk.size()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
