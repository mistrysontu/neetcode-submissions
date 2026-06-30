class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0, idx = 0, visited = 0;
        int cnt = 0;
        int n = gas.size();
        while(cnt != n && visited <= n*n) {
            currGas += gas[idx];
            if(currGas >= cost[idx]) {
                currGas -= cost[idx];
                cnt++;
            }
            else {
                currGas = 0;
                cnt =  0;
            }
            visited++;
            idx = (idx+1) % n;
        }
        return visited > n*n ? -1: idx;
    }
};
