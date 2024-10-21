class Solution {
public:
    string reverseVowels(string s) {
        
        string vowels = "aeiouAEIOU";

        int l = 0, r = s.size() - 1;

        bool fl = 0, fr = 0;

        while(l < r){
            if(vowels.find(string(1, s[l])) != string::npos) fl = 1;
            if(vowels.find(string(1, s[r])) != string::npos) fr = 1;

            if(fl && fr){
                swap(s[l], s[r]);
                fl = 0;
                fr = 0;
            }

            if(!fl) l++;
            if(!fr) r--;
        }
        
        return s;
    }
};