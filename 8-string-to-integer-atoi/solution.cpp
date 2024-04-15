class Solution {
public:
    int myAtoi(string s) {
        
        int flag = 1;
        int if_negative = 1;

        int result = 0;

        vector<int> digits;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            
            if(c == ' '){
                if(!flag) break;
                else continue;
            }
            else if(c == '-' || c == '+'){
                if(!flag) break;
                else if(c == '-') if_negative *= -1;
                flag = 0;
            }
            else if(c == '.' || c < 48 || c > 57 ) break;
            else{
                flag = 0;
                digits.push_back(c - 48);
            }
        }

        int p = 0;
        int inc = 0;

        for(int i = digits.size() - 1; i > -1; i--){
            if(p + 1 < 10 || (p + 1 == 10 && digits[i] < 3) || (p + 1 > 10 && digits[i] == 0)) inc = pow(10, p) * digits[i] * if_negative;
            else{
                if(if_negative < 0) return INT_MIN;
                else return INT_MAX;
            }
            if(if_negative < 0 && INT_MIN - result >= inc) return INT_MIN;
            else if(if_negative > 0 && INT_MAX - result <= inc) return INT_MAX;
            result += inc; 
            p++;
        }
        
        cout << "hi";
        return result;
    }
};