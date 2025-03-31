using ll = long long;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        priority_queue<ll> maxHeap;

        for(int i = 1; i < weights.size(); i++){
            ll sum = weights[i] + weights[i - 1];

            minHeap.push(sum);
            maxHeap.push(sum);
        }

        ll mini = 0, maxi = 0;

        for(int i = 0; i < k - 1; i++){
            mini += minHeap.top();
            maxi += maxHeap.top();

            minHeap.pop();
            maxHeap.pop();
        }

        return maxi - mini;
    }
};