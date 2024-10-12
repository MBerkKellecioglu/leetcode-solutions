class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);

        if(total_gas < total_cost) return -1;
        
        vector<int> diffs;

        int total = 0, sol = 0;

        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];

            if(total < 0){
                total = 0;
                sol = i + 1;
            }
        }

        return sol;
    }
};