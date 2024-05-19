class Solution {
public:
    string countAndSay(int n){

        string base = "1";


        for(int i = 0; i < n - 1; i++){
            base = RLE(base);
            
            cout << base << endl;
        }

        return base;
    }

    string RLE(string num){

        string res = "";

        for(int i = 0; i < num.size(); i++){
            char curr = num[i];
            int count = 1;

            i++;
            
            while(curr == num[i]){
                i++;
                count++;
            }

            res += to_string(count) + curr;
            i--;
        }

        return res;
    }
};