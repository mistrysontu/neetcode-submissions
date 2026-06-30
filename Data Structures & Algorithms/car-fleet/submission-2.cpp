class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int cnt = 0;
        vector<pair<int, int>> arr;

        for(int i = 0; i < speed.size(); i++){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end(), [=](pair<int, int> &a, pair<int, int> &b){return a.first > b.first;});
        double finish = 0.0;

        for(auto elem: arr){
            int p = elem.first;
            int s = elem.second;

            double time = (target - p) / (s*1.0);
            if(finish < time){
                cnt++;
                finish = time;
            }
            
        }
        return cnt;
    }
};
