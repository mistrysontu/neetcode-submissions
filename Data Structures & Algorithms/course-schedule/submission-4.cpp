class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for(auto elem: prerequisites){
            inDegree[elem[0]]++;
            adjList[elem[1]].push_back(elem[0]);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(q.size()){
            auto curr = q.front();
            q.pop();
            for(auto nei: adjList[curr]){
                inDegree[nei]--;
                if(inDegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};
