class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int curr = 0, res = 0, n = heights.size();

        stack<pair<int, int>> stk;

        for(int i = 0; i < n; i++){
            int idx = i;
            while(stk.size() && stk.top().first > heights[i]){
                curr = (i - stk.top().second) * stk.top().first;
                idx = stk.top().second;
                res = max(res, curr);
                stk.pop();
            }
            stk.push({heights[i], idx});
        }

        while(stk.size()){
            res = max(res, (n - stk.top().second) * stk.top().first);
            stk.pop();
        }
        return res;
    }
};
