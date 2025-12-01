class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if(k == 0) return 0;

        vector<int> buy(k+1, INT_MAX);

        vector<int> profit(k+1, 0);

        for (int p : prices){
            for (int i = 1; i <= k; i++){
                buy[i] = min(buy[i], p - profit[i-1]);

                profit[i] = max(profit[i], p - buy[i]);
            }
        }

        return profit[k];
    }
};
