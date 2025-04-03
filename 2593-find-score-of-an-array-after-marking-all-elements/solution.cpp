using ll = long long;

struct Compare {
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, Compare> minHeap;

        ll ans = 0;

        for(int i = 0; i < nums.size(); i++){
            minHeap.push({ll(nums[i]), i});
        }

        while(!minHeap.empty()){
            pair<ll, ll> tmp = minHeap.top();
            minHeap.pop();

            if(nums[tmp.second] == -1) continue;

            ans += tmp.first;

            if(tmp.second - 1 > -1) nums[tmp.second - 1] = -1;
            if(tmp.second + 1 < nums.size()) nums[tmp.second + 1] = -1;
        }

        return ans; 
    }
};