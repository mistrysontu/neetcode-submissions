class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for(auto elem: edges){
            adjList[elem[0]].push_back(elem[1]);
            adjList[elem[1]].push_back(elem[0]);
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                cnt++;
                visited[i] = true;
                q.push(i);
                while(q.size()){
                    auto curr = q.front();
                    q.pop();
                    for(auto adj: adjList[curr]){
                        if(!visited[adj]) q.push(adj);
                        visited[adj] = true;
                    }
                }
            }
        }
        return cnt;
    }
};
