class Solution {
    using ll = long long;
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        ll r = 0, ans = INT_MAX, sum = 0, n = nums.size();

       deque<pair<ll,ll>> q;

        for(r; r < n; r++){
            sum += nums[r];

            if(sum >= k) ans = min(ans, r + 1);
            
            while(!q.empty() && sum - q.front().first >= k){
                ans = min(ans, r - q.front().second);
                q.pop_front();
            }

            while(!q.empty() && q.back().first >= sum) q.pop_back();  
            
            q.push_back({sum, r});
        }

        return ans = (ans == INT_MAX) ? -1 : ans;

    }
};