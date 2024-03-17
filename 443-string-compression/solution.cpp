class Solution {
public:
    int compress(vector<char>& chars) {

        int freq = 1, l = 1, r = 1;
        char prev = chars[0];

        while(r < chars.size()){
            if(chars[r] == prev){
                freq++;
                r++;
            }
            else{
                chars.erase(chars.begin() + l, chars.begin() + r);

                if(l < chars.size()) prev = chars[l];
                
                vector<char> digits = getDigits(freq);
                for(int digit : digits){
                    chars.insert(chars.begin() + l, digit);
                    l++;
                }
                l++;
                r = l;
                freq = 1;
            }
        }

        chars.erase(chars.begin() + l, chars.begin() + r);
        vector<char> digits = getDigits(freq);
        for(int digit : digits) chars.push_back(digit);

        return int(chars.size());
    }

    vector<char> getDigits(int num){

        vector<char> digits;

        while(num > 0){
            int digit = num % 10;
            digits.push_back(digit + 48);
            num /= 10;
        }
        
        if(digits.size() == 1 && digits[0] == '1'){
            digits.clear();
            return digits;
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};