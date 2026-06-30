class KthLargest {
public:
    int idx;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        idx = k;
        for(auto elem: nums){
            if(minHeap.size() >= k){
                if(elem > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(elem);
                }
            }
            else{
                minHeap.push(elem);
            }

        }
    }
    
    int add(int val) {
        if(minHeap.size() == idx){
            if(val > minHeap.top()){
                minHeap.pop();
                minHeap.push(val);
            }
        }
        else{
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
