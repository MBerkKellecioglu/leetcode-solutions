class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int sol = *max_element(nums.begin(), nums.end());

        int curr_max = 1, curr_min = 1;


        for(int i = 0; i < nums.size(); i++){

            int num = nums[i];

            int tmp = curr_max * num;

            curr_max = max({curr_min * num, curr_max * num, num});
            curr_min = min({tmp, curr_min * num, num});

            sol = max(curr_max, sol);
        }

        return sol;
    }
};