class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int inc = 1;

        if(digits.back() + 1 < 10){
            digits[digits.size() - 1]++;
            return digits;
        }
        else{
            int sum = digits[digits.size() - 1] + 1;
            
            digits[digits.size() - 1] = sum % 10;
            inc = sum / 10;

            for(int i = digits.size() - 2; i > -1; i--){
                sum = digits[i] + inc;

                if(sum >= 10){
                    digits[i] = sum % 10;
                    inc = sum / 10;
                }
                else{
                    digits[i] = sum;
                    return digits;
                }
            }
        }

        digits.insert(digits.begin(), inc);
        

        return digits;
    }
};