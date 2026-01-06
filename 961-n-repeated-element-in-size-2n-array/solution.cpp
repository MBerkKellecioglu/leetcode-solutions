class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        map<int, int> freqs;

        int n = nums.size() / 2;

        for(int num : nums){
            freqs[num]++;
        }

        for(auto freq : freqs){
            if(freq.second == n) return freq.first;
        }

        return 0;
    }
};