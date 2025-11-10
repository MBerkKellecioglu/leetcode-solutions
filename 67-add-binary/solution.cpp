class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.size() < b.size()) swap(a, b);

        while(a.size() > b.size()) b.insert(0, "0");

        int plus = 0;

        string ans = "";

        for(int i = a.size() - 1; i > -1; i--){
            int sum = (a[i] - '0') + (b[i] - '0') + plus;
            
            plus = sum / 2;

            (sum % 2) ? ans.insert(0, "1"): ans.insert(0, "0");
        }

        if(plus) ans.insert(0, "1");

        return ans;
    }
};