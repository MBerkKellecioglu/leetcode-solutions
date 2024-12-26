class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int> mono; // store indexes

        for(int i = 0; i < prices.size(); i++){
            while(!mono.empty() && prices[i] <= prices[mono.top()]){
                int j = mono.top();

                prices[j] -= prices[i];

                mono.pop();
            }

            mono.push(i);
        }

        return prices;   
    }
};