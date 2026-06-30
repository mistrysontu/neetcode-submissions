class Solution {
public:
    bool isPossible(vector<int> &piles, int h, int num){
        int cnt = 0;
        for(auto elem: piles){
            cnt += ceil(elem / (num*1.0));
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n) return -1;
        int res = INT_MAX;
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPossible(piles, h, mid)){
                res = min(res, mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return res;
    }
};
