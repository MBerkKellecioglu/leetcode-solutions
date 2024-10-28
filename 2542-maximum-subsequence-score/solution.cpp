class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        long long int ans = 0, sum = 0;
        
        vector<pair<int,int>> pairs(n);

        priority_queue <int, vector<int>, greater<int> > pq; 

        for(int i = 0; i < n; i++){
            pairs[i].first = nums2[i];
            pairs[i].second = nums1[i];
        }

        sort(pairs.begin(), pairs.end(), comp);

        for(auto p : pairs){
            sum += p.second;
            pq.push(p.second);

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                ans = max(ans, sum * p.first);
            }
        }

        return ans;
    }

    static bool comp (pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};