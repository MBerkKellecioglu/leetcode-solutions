class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        bool ans = false, flag = false; 

        int dst = 0;

         for(int i = 0; i < nums.size(); i++){
            if(flag == true) dst--;

            if(nums[i] == 1){
                if(!flag){
                    flag = true;
                    dst = k;    
                }
                else{
                    if(dst < 0){
                        dst = k;
                    }
                    else return false;
                }
            }
        }

        return true;
    }
};