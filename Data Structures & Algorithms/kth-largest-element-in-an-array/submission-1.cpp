class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto elem: nums){
            if(k == 0){
                if(pq.top() < elem){
                    pq.pop();
                    pq.push(elem);
                }
            }
            else{
                pq.push(elem);
            }
            if(k) k--;
        }
        return pq.top();
    }
};
