class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(int num : nums){
            uset.insert(num);
        }
        int cnt = 0, res = 0;

        for(auto elem: uset){
            cnt = 0;
            if(uset.count(elem-1) == 0){
                while(uset.count(elem++)){
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
