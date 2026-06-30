class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDegree(n+1, 0), outDegree(n+1, 0);

        for(auto elem: trust) {
            inDegree[elem[1]]++;
            outDegree[elem[0]]++;
        }

        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == n-1 && outDegree[i] == 0) return i;
        }

        return -1;
    }
};