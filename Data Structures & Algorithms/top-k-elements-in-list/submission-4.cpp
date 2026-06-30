class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for(auto n: nums) {
            // if(umap.find(n) == umap.end()) {
            //     umap[n] = 1;
            // }
            // else {
            //     umap[n]++;
            // }

            umap[n]++;
        }

        vector<pair<int, int>> temp;

        for(pair<int, int> elem: umap) {
            temp.push_back(elem);
        }

        sort(temp.begin(), temp.end(), 
            [] (pair<int, int> x, pair<int, int> y) {
                // if(x.second > y.second) {
                //     return true;
                // }
                // return false;
                return x.second > y.second;
            }
        );

        vector<int> res;

        for(int i = 0; i < k; i++) {
            res.push_back(temp[i].first);
        }
        return res;
    }
};


// 3, 4, 5, 2, 3, 3, 4, 3, 5, 6, 4, 4, 4

// 2; 1
// 3; 4
// 4; 5
// 5: 2
// 6: 1