class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int i = 0, sz = nums.size(), mn = INT_MIN, ans = 0;

        while(i < sz){

            int curr = nums[i], counter = 1;

            while(i + 1 < sz && curr == nums[i + 1]){
                counter++;
                i++;
            }

            int lower = max(mn + 1, curr - k), higher = curr + k;

            int range = higher - lower + 1;

            int distinct = (counter >= range) ? range : counter;

            ans += distinct;

            mn = (counter >= range) ? higher :  lower + counter - 1;
            
            i++;
        }

        return ans;
    }
};