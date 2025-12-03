class Solution {
public:
    int maxProfit(vector<int>& prices){

        int buy = prices[0], sell = 0;

        for(int i = 1; i < prices.size(); i++){
            buy = min(buy, prices[i] - sell);

            sell = max(sell, prices[i] - buy);
        }

        return sell;
    }
};