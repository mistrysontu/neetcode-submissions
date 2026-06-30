class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int ns = newInterval[0], ne = newInterval[1];
        vector<vector<int>> res;
        for(vector<int> i: intervals){
            int s = i[0], e = i[1];
            if(ns == -1 || ne == -1){
                res.push_back(i);
                continue;
            }
            if(s < ns && e < ns){
                res.push_back(i);
            }
            else if(s > ne && e > ne){
                if(ns != -1){
                    res.push_back({ns, ne});
                    ns = -1;
                    ne = -1;
                }
                res.push_back(i);
            }
            else{
                ns = min(ns, s);
                ne = max(ne, e);
            }
        }
        if(ns != -1){
            res.push_back({ns, ne});
        }
        return res;
    }
};
