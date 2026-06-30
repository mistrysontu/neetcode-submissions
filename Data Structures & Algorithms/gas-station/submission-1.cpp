class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int j = -1;
        int tank = 0;
        for(int i = 0; i < n; i++){
            tank = gas[i] - cost[i];
            if(tank < 0) continue;
            
            int j = (i+1)%n;
            while(j != i){
                tank += (gas[j] - cost[j]);
                if(tank < 0) break;
                j = (j+1) % n;
            }
            if(i == j) return i;
        }
        return -1;
    }
};
