class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX, second = INT_MAX;

        for(int& last : nums){
            if(last <= first){
                first = last;
            }
            else if(last <= second){
                second = last;
            }
            else return true;
        }

        return false;
    }
};