class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.size() - 1, m = num2.size() - 1;

        vector<int> digits(num1.size() + num2.size(), 0);

        string res = "";

        for(int i = n; i > -1; i--){
            for(int j = m; j > -1; j--){
                int digit = (num1[i] - 48) * (num2[j] - 48);

                digits[i + j + 1] += digit;
                digits[i + j] += digits[i + j + 1] / 10;
                digits[i + j + 1] = digits[i + j + 1] % 10;
            }
        }

        int ind = 0;

        while(ind < digits.size() && digits[ind] == 0) digits.erase(digits.begin() + ind);
        
        for(auto elements : digits) res += to_string(elements);
        
        return res;
    }
};