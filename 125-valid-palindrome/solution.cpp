class Solution {
public:
    bool isPalindrome(string s){
        string reduced_s;
        for(auto elements : s) if((isalpha(elements) || isdigit(elements )) && elements != ' ') reduced_s += tolower(elements);
        
        s = reduced_s;
        reverse(reduced_s.begin(), reduced_s.end());
        if(s == reduced_s) return true;
        else return false;

        return true;
    }
};