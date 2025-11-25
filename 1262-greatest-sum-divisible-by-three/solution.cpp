class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int sum = 0;

        int smallest_one = INT_MAX, smallest_two = INT_MAX;

        for(auto num : nums){
            sum += num;

            if(num % 3 == 1){
                if(smallest_one == INT_MAX){
                    smallest_one = num;
                    continue;
                }
                smallest_two = min(smallest_two, num + smallest_one);
                smallest_one = min(smallest_one, num);
            }

            if(num % 3 == 2){
                if(smallest_two == INT_MAX){
                    smallest_two = num;
                    continue;
                }
                smallest_one = min(smallest_one, num + smallest_two);
                smallest_two = min(smallest_two, num);
            }
        }

        if(sum % 3 == 0) return sum;

        if(sum % 3 == 1) return sum - smallest_one;

        return sum - smallest_two;
    }
};