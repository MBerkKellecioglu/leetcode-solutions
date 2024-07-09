class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int pivot = -1;
        
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                pivot = i;
                break;
            }

        }

        cout << pivot;

        if(pivot == -1) reverse(nums.begin(), nums.end());
        else{
            for(int i = nums.size() - 1; i >= pivot; i--){
                if(nums[pivot - 1] < nums[i]){
                    int tmp = nums[i];
                    nums[i] = nums[pivot - 1];
                    nums[pivot - 1] = tmp;
                    break;
                }
            }
            reverse(nums.begin() + pivot, nums.end());
        }
    }
};