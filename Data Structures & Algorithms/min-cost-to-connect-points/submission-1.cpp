class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> adjList;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                adjList[i].push_back({dist, j});
                adjList[j].push_back({dist, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        vector<bool> visited(n, false);
        vector<int> cost(n, INT_MAX);
        cost[0] = 0;
        int mst = 0;
        // visited[0] = true;
        while(q.size()){
            auto curr = q.top();
            q.pop();
            if(visited[curr.second]) continue;
            mst += curr.first;
            visited[curr.second] = true;
            for(auto nei: adjList[curr.second]){
                if(!visited[nei.second]){
                    if(nei.first < cost[nei.second]){
                        q.push({nei.first, nei.second});
                    }
                }
            }
        }
        return mst;
    }
};
