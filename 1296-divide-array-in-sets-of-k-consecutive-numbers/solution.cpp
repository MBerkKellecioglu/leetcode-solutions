class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        while(!freq.empty()){
            int mini = freq.begin()->first;
            
            for(int cons = mini; cons < mini + k; cons++){
                if (freq.find(cons) == freq.end()){
                    return false;
                }

                freq[cons]--;

                if(!freq[cons]){
                    freq.erase(cons);
                }
            }
        }

        return true;
    }
};