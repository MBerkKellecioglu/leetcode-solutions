class Solution {
public:
    int longestSquareStreak(vector<int>& nums){
        
        unordered_set<long long int> cache(nums.begin(), nums.end());

        unordered_map<long long int, long long int> dp;

        int ans = -1, seq;

        for(long long int n : nums){
            if(!dp.count(n) && cache.count(n*n)){
                seq = 2 + rec(dp, cache, n*n);
                ans = max(seq, ans);
            }
        }

        return ans;
    }

    int rec(unordered_map<long long int,long long int>& dp, unordered_set<long long int>& cache, long long int n){

        if(n > 100000) return 0;

        if(dp.count(n)){
            return dp[n];
        }

        if(cache.count(n*n)){
            return dp[n] = 1 + rec(dp, cache, n*n);
        }
        
        return dp[n] = 0;
    }
};