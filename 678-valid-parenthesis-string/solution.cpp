class Solution {
public:
    bool checkValidString(string s) {
        
        int left_min = 0, left_max = 0;

        // Solution with only 2 variables same logic as stack solution

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                left_min++;
                left_max++;
            }
            else if(s[i] == ')'){
                left_min--;
                left_max--;
                
                if(left_max < 0) return false;
            }
            else{
                left_min--;
                left_max++;
            }
            if(left_min < 0) left_min = 0;
        }

        if(left_min == 0 || left_max == 0) return true;

        return false;
    }
};