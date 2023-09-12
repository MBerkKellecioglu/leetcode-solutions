class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int left_ind = 0, right_ind = numbers.size() - 1;

        while(left_ind < right_ind){
            if(numbers[left_ind] + numbers[right_ind] > target) right_ind--;
            else if(numbers[left_ind] + numbers[right_ind] < target) left_ind++;
            else{
                std::vector<int> sol = {left_ind + 1, right_ind + 1};
                return sol;
            }
        }
        return numbers;
    }
};