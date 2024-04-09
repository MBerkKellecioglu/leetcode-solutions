class Solution {
public:
    int romanToInt(string s) {

       map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

        int result = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I' && i + 1 < s.size()){
                if(s[i + 1] == 'V') result += 4;
                else if(s[i + 1] == 'X') result += 9;
                else{
                    result += roman[s[i]];
                    continue;
                }

                i++;
                continue;
            }
            if(s[i] == 'X' && i + 1 < s.size()){
                if(s[i + 1] == 'L') result += 40;
                else if(s[i + 1] == 'C') result += 90;
                else{
                    result += roman[s[i]];
                    continue;
                }

                i++;
                continue;
            }
            if(s[i] == 'C' && i + 1 < s.size()){
                if(s[i + 1] == 'D') result += 400;
                else if(s[i + 1] == 'M') result += 900;
                else{
                    result += roman[s[i]];
                    continue;
                }

                i++;
                continue;
            }

            result += roman[s[i]];
        }
        
        return result; 
    }
};