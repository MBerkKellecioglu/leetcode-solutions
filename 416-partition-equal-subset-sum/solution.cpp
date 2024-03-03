class Solution {
public:
    bool canPartition(vector<int>& nums){
        
        int sum = 0;

        for(int num : nums) sum += num;

        if(sum % 2 == 1) return false;

        if(sum % 2 == 0){
            sum /= 2;
            vector<vector<int>> cache(nums.size() + 1, vector<int>(sum + 1, -1));
            return rec(nums, sum, 0, cache);
        }

        return false;
    }

    bool rec(vector<int>& nums, int sum, int ind, vector<vector<int>>& cache){

        if(ind >= nums.size() || sum < 0) return false;
        if(sum == 0) return true;

        if(cache[ind][sum] != -1) return cache[ind][sum];

        return cache[ind][sum] = rec(nums, sum, ind + 1, cache) || rec(nums, sum - nums[ind], ind + 1, cache);
    }
};