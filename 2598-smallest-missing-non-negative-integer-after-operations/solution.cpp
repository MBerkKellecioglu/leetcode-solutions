class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        int sz = nums.size();
        
        map<int, int> freq;

        for(auto n : nums){
            int f = (n % value < 0) ? n % value + value : n % value;

            freq[f]++;
        }

        int counter = 0;

        while(1){
            if(freq[counter % value] > 0) freq[counter % value]--;
            else return counter;

            counter++; 
        }
       

        return -1;
    }
};