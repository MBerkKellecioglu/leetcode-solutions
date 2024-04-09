class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());

        pair<int, int> result = {INT_MAX, INT_MAX}; // first is dif, second is sum //

        for(int i = 0; i < nums.size() - 2; i++){
            int anchor = nums[i];
            int left_ind = i + 1;
            int right_ind = nums.size() - 1;
            while(left_ind < right_ind){
                int sum = anchor + nums[left_ind] + nums[right_ind];
                int dif = 0;

                dif = sum - target;

                if(abs(dif) < result.first){
                    result.first = abs(dif);
                    result.second = sum;
                }
                
                if(dif > 0) right_ind--;
                else if(dif < 0) left_ind++;
                else return sum;
            }
        }

        return result.second;
    }
};