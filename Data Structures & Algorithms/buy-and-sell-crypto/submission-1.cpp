class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;

        for(auto price: prices){
            buy = max(buy, -price); // negative value as small as possible / buy as cheap as possible.
            sell = max(sell, buy + price);
        }
        return sell;
    }
};
