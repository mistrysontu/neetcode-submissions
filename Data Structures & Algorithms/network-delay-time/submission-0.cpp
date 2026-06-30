class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto time: times){
            adjList[time[0]].push_back({time[1], time[2]});
        }
        vector<int> cost(n+1, INT_MAX);
        cost[k] = 0;
        cost[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({k, 0});
        while(pq.size()){
            auto curr = pq.top();
            pq.pop();

            for(auto nei: adjList[curr.first]){
                if(cost[nei.first] > curr.second + nei.second){
                    cost[nei.first] = curr.second + nei.second;
                    pq.push({nei.first, cost[nei.first]});
                }
            }
        }
        int res = INT_MIN;
        for(auto c: cost){
            if(c == INT_MAX) return -1;
            res = max(res, c);
        }
        return res;
    }
};
