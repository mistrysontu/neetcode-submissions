struct hash_pair{
    template<class t1, class t2>
    size_t operator()(const pair<t1, t2> & p) const{
        auto hash1 = hash<t1>{}(p.first);
        auto hash2 = hash<t2>{}(p.second);

        return hash1 ^ (hash2 * 31);
    }
};

class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        unordered_set<pair<int, int>, hash_pair> set1, set2;

        queue<pair<int, int>> q1, q2;

        for(int i = 0; i < m; i++){
            q1.push({i, 0});
            q2.push({i, n-1});
            set1.insert({i, 0});
            set2.insert({i, n-1});
        }

        for(int j = 0; j < n; j++){
            q1.push({0, j});
            q2.push({m-1, j});
            set1.insert({0, j});
            set2.insert({m-1, j});
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(q1.size()){
            auto curr = q1.front();
            q1.pop();

            for(auto dir: dirs){
                int newi = curr.first + dir[0];
                int newj = curr.second + dir[1];
                if(isValid(newi, newj, m, n) && !set1.count({newi, newj}) && heights[newi][newj] >= heights[curr.first][curr.second]){
                    q1.push({newi, newj});
                    set1.insert({newi, newj});
                }
            }
        }

        while(q2.size()){
            auto curr = q2.front();
            q2.pop();

            for(auto dir: dirs){
                int newi = curr.first + dir[0];
                int newj = curr.second + dir[1];
                if(isValid(newi, newj, m, n) && !set2.count({newi, newj}) && heights[newi][newj] >= heights[curr.first][curr.second]){
                    q2.push({newi, newj});
                    set2.insert({newi, newj});
                }
            }
        }

        vector<vector<int>> result;
        for (const auto& p : set1) {
            if (set2.count(p)) result.push_back({p.first, p.second});
        }
        return result;


    }
};
