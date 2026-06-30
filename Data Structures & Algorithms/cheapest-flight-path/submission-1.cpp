class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto flight: flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adjList[u].push_back({v, w});
        }
        k += 2;
        queue<pair<int, int>> q; // {airport_k, price_till_airport_k}
        q.push({src, 0});
        int res = INT_MAX;
        while(k--) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto [u, w] = q.front(); q.pop();
                if(u == dst) res = min(res, w);
                for(auto [v, w1]: adjList[u]) {
                    q.push({v, w+w1});
                }
            }
        }

        // while(q.size()) {
        //     auto [u, w] = q.front(); q.pop();
        //     if(u == dst) res = min(res, w);
        // }
        return res == INT_MAX ? -1 : res;
    }
};
