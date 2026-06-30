class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> meanHeap;

    MedianFinder() {    
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || maxHeap.top() >= num){
            maxHeap.push(num);
        }
        else{
            meanHeap.push(num);
        }
        if(maxHeap.size() - 1 > meanHeap.size()){
            meanHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (meanHeap.size() > maxHeap.size()) {
            maxHeap.push(meanHeap.top());
            meanHeap.pop();
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + meanHeap.size()) % 2 == 1){
            return maxHeap.top();
        }
        return (maxHeap.top() + meanHeap.top()) / 2.0;

    }
};
