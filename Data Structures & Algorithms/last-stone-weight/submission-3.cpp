class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto stone: stones){
            q.push(stone);
        }
        while(q.size() > 1){
            auto first = q.top();
            q.pop();
            auto second = q.top();
            q.pop();
            if(first == second) continue;
            q.push(abs(first - second));
        }
        if(q.size()) return q.top();
        return 0;
    }
};
