class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;

        for(auto point: points){
            double dist = sqrt(pow(point[0], 2) + pow(point[1], 2));
            if(k == 0){
                if(pq.top().first > dist){
                    pq.pop();
                    pq.push({dist, point});
                }
            }
            else{
                pq.push({dist, point});
            }
            if(k) k--;
            
        }

        vector<vector<int>> res;

        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
