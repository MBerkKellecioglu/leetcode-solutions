class Solution {
public:
    int maxProfit(vector<int>& prices){
        
        map<pair<int, string>, int> dp;

        return dfs(dp, prices, 0, "buy");
    }


    int dfs(map<pair<int, string>, int>& dp, vector<int>& prices, int ind, string flag){
        
        if(ind >= prices.size()) return 0;
        
        if(dp.find({ind, flag}) != dp.end()) return dp[{ind, flag}];
        
        int candidate1 = INT_MIN, candidate2 = INT_MIN, candidate3 = INT_MIN;

        if(flag == "buy"){
            candidate1 = dfs(dp, prices, ind + 1, "sell") - prices[ind];
        }
        else if(flag == "sell"){
            candidate2 = dfs(dp, prices, ind + 2, "buy") + prices[ind];
        }

        candidate3 = dfs(dp, prices, ind + 1, flag); 
        
        return dp[{ind, flag}] = max({candidate1, candidate2, candidate3});
    }
};