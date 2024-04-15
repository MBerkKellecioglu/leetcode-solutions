class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        vector<int> digits; 

        while(x > 0){
            digits.push_back(x % 10);
            x /= 10;
        }

        int l = 0, r = digits.size() - 1;

        while(l <= r){
            if(digits[l] != digits[r]) return false;
            else{
                l++;
                r--;
            }
        }

        return true;
    }
};