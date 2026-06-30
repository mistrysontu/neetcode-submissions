class UnionFind{
    vector<int> parent, rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
            rank.resize(n, 0);
        }
        int Find(int x){
            if(x != parent[x]){
                parent[x]= Find(parent[x]);
            }
            return parent[x];
        }
        void Union(int x, int y){
            if(Find(x) != Find(y)){
                x = Find(x);
                y = Find(y);
                if(rank[x] == rank[y]){
                    parent[y] = x;
                    rank[x]++;
                }
                else if(rank[x] > rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                }
            }
        }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        UnionFind uf(n);
        for(auto edge: edges){
            if(uf.Find(edge[0]) == uf.Find(edge[1])){
                return edge;
            }
            uf.Union(edge[0], edge[1]);
        }
        return {};
    }
};
/*
        1
    4 3


*/
