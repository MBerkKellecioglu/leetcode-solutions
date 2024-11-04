class Solution {
public:
    string compressedString(string word) {
        
        int r = 0;

        string comp = "";

        while(r < word.size()){
            if(r < word.size() && word[r] == word[r + 1]){
                int l = r;

                while(r < word.size() && word[r] == word[r + 1]){
                    r++;
                }

                int sz = (r - l) + 1;
                string curr = string(1,word[r]);

                while(sz > 0){
                    comp += (sz <= 9) ? to_string(sz) + curr : "9" + curr;
                    sz -= 9;
                }
            }
            else comp += "1" + string(1, word[r]);
            r++;
        }

        return comp;
    }
};