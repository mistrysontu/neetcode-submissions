class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;

        for(auto elem: triplets){
            if(elem[0] > target[0] || elem[1] > target[1] || elem[2] > target[2]) continue;

            if(elem[0] == target[0]) a = true;
            if(elem[1] == target[1]) b = true;
            if(elem[2] == target[2]) c = true;
        }
        return a && b && c;
    }
};
