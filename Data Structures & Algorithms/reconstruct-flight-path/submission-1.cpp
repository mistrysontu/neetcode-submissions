class Solution {
public:
    void DFS(string val, unordered_map<string, vector<string>> &umap, vector<string> &res){
        while(umap[val].size()){
            auto next = umap[val].back();
            umap[val].pop_back();
            DFS(next, umap, res);
        }
        res.push_back(val);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> umap;

        for(auto ticket: tickets){
            umap[ticket[0]].push_back(ticket[1]);
        }
        for(auto &elem: umap){
            sort(elem.second.begin(), elem.second.end(), greater<string>());
        }

        vector<string> res;
        DFS("JFK", umap, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
