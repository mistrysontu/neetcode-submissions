class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> need(amount+1, INT_MAX);
        need[0] = 0;

        for(auto coin: coins){
            for(int i = coin; i <= amount; i++){
                if(need[i-coin] != INT_MAX){
                    need[i] = min(need[i], need[i-coin] + 1);
                }
            }
        }
        return need[amount] == INT_MAX ? -1 : need[amount] ;
    }
};
