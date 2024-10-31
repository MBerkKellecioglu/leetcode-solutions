class Solution {
    #define INT_MAX 9223372036854775807
    using ll = long long;
    int count = 0;
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> all_factories;

        for(auto& f : factory){
            while(f[1] > 0){
                f[1]--;
                all_factories.push_back(f[0]);
            }
        }

        vector<vector<ll>> dp(robot.size(), vector<ll>(all_factories.size(), -1));

        return dfs(robot, all_factories, dp, robot.size() - 1, all_factories.size() - 1);
    }

    ll dfs(vector<int>& robot, vector<int>& factory, vector<vector<ll>>& dp, int r_ind, int f_ind){
        
        if(r_ind < 0) return 0;
        
        if(f_ind < 0) return INT_MAX; 
        
        if(dp[r_ind][f_ind] != -1){
            return dp[r_ind][f_ind];
        }

        ll candidate1 = dfs(robot, factory, dp, r_ind - 1, f_ind - 1);
        ll candidate2 = dfs(robot, factory, dp, r_ind, f_ind - 1);

        if(candidate1 != INT_MAX) candidate1 += abs(factory[f_ind] - robot[r_ind]);

        return dp[r_ind][f_ind] = min(candidate1, candidate2);
    }
};