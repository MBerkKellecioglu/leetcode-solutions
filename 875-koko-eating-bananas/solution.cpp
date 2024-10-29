class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        long long left_val = 1, right_val = *max_element(piles.begin(), piles.end()), mid_val, count = 0, sol;


        while(left_val <= right_val){
            mid_val = (left_val + right_val) / 2;
            for(int i = 0; i < piles.size(); i++) count += ceil(double(piles[i]) / double(mid_val));
            if(count > h) left_val = mid_val + 1;
            else{
                right_val = mid_val - 1;
                sol = mid_val;
            }
            count = 0;
        }
        return sol;   
    }

};