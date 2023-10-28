class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> cache;
        vector<int> sol;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int second_ind = cache[target - num];
            if(second_ind) return{i, second_ind - 1};
            cache[num] = i + 1;
        }

        return sol;
    }
};