class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int l = 0, r = 0, n = nums.size();

        double sum = 0, ans = 0, w = k;
        
        // Creating our window
        for(r; r < k; r++){
            sum += nums[r];
        }

        ans = sum;

        for(r; r < n; r++){
            sum -= double(nums[l]);
            sum += double(nums[r]);

            l++;

            ans = max(ans, sum);
        }

        cout << ans;

        return ans / w;
    }
};