class Solution {
public:
    string intToRoman(int num){

        string sol = "";
        int i = 0;
        int digit;

        map<int, string> roman = {
            make_pair(1, "I"),
            make_pair(2, "II"),
            make_pair(3, "III"),
            make_pair(4, "IV"),
            make_pair(5, "V"),
            make_pair(6, "VI"),
            make_pair(7, "VII"),
            make_pair(8, "VIII"),
            make_pair(9, "IX"),
        };

        map<char, char> SDC = {
            make_pair('I', 'X'), 
            make_pair('V', 'L'),
            make_pair('X', 'C'),
        };

        map<char, char> TDC = {
            make_pair('I', 'C'),
            make_pair('V', 'D'),
            make_pair('X', 'M'),
        };

        map<char, char> FDC = { make_pair('I', 'M') };

        vector<map<char, char>> mp_vec{SDC, TDC, FDC};

        digit = num % 10;
        sol += roman[digit];
        num /= 10;


        while(num > 0){
            int digit = num % 10;

            sol.insert(0, convert(digit, roman, mp_vec[i]));

            num /= 10;
            i++;
        }

        return sol;
    }

    string convert(int& digit, map<int, string>& roman, map<char, char>& conversion){

        string base = roman[digit];

        for(int i = 0; i < base.size(); i++) base[i] = conversion[base[i]];
        
        return base;
    }
};