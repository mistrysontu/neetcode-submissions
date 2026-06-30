class Comp{
    public:
        int operator() (pair<int, int> &a, pair<int, int> &b){
            return a.second > b.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto elem: nums){
            umap[elem]++;
        }
        vector<int> res;

        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;

        for(auto elem: umap){
            if(pq.size() >= k){
                if(pq.top().second < elem.second){
                    pq.pop();
                    pq.push(elem);
                }
            }
            else{
                pq.push(elem);
            }
        }

        while(pq.size()){
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.first);
        }
        return res;
    }
};
