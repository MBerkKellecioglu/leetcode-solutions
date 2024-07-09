class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1) return true;
        
        int prev = nums.back();

        nums.back() = 1;

        for(int i = nums.size() - 2; i > -1; i--){
            if(nums[i] > 0){
                if(nums[i + 1] == 1){
                    prev = nums[i];
                    nums[i] = 1;
                }
                else if(nums[i] <= prev + 1){
                    prev = nums[i];
                    nums[i] = -1;
                }
                else{
                    int flag = 0;

                    int rep = 0;
                    for(int k = i + prev + 2; rep < nums[i] - prev - 1; rep++){
                        if(nums[k] == 1){
                            flag = 1;
                            break;
                        }
                        k++;
                    }

                    prev = nums[i];

                    if(flag == 1) nums[i] = 1;
                    else nums[i] = -1;
                    
                }
            }
            else{
                prev = nums[i];
                nums[i] = -1;
            }
        }



        if(nums[0] == -1) return false;
        else return true;
    }
};