class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for(auto elem: prerequisites){
            inDegree[elem[0]]++;
            adjList[elem[1]].push_back(elem[0]);
        }
        
        vector<int> res;
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                res.push_back(i);
                q.push(i);
            }
        }

        while(q.size()){
            auto curr = q.front();
            q.pop();
            for(auto nei: adjList[curr]){
                inDegree[nei]--;
                if(inDegree[nei] == 0){
                    res.push_back(nei);
                    q.push(nei);
                }
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] != 0){
                return {};
            }
        }
        return res;
    }
};
