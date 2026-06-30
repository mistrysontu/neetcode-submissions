class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char task: tasks){
            int i = task - 'A';
            count[i]++;
        }
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for(auto elem: count){
            if(elem > 0){
                pq.push(elem);
            }
        }
        int time = 0;
        while(pq.size() || q.size()){
            time++;
            if(pq.size() == 0){
                time = q.front().second;
            }
            else{
                auto curr = pq.top() -1;
                pq.pop();
                if(curr > 0){
                    q.push({curr, time + n});
                }
            }
            if(q.size() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
