class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stk;

        for(int i = n-1; i >= 0; i--){
            while(stk.size() && stk.top().first <= temperatures[i]){
                stk.pop();
            }
            if(!stk.size()){
                res[i] = 0;
            }
            else res[i] = stk.top().second - i;
            stk.push({temperatures[i], i});
        }
        return res;         
    }
};
