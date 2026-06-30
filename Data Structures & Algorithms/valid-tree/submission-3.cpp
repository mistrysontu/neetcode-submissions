class Solution {
    vector<int> parent, rank;
public:
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void _union(int x, int y){
        if(find(x) != find(y)){
            if(rank[x] > rank[y]){
                parent[y] = x;
            }
            else if(rank[x] < rank[y]){
                parent[x] = y; 
            }
            else{
                parent[y] = x;
                rank[x]++;
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        if(edges.size() >= n) return false;
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto elem: edges){
            _union(elem[0], elem[1]);
        }
        int root = find(0);
        for(int i = 0; i < n; i++){
            if(find(i) != root) return false;
        }
        return true;
    }
};
