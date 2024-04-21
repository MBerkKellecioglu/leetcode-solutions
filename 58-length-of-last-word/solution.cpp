class Solution {
public:
    int lengthOfLastWord(string s){

        int flag = 0;

        int count = 0;

        for(int i = s.size() - 1; i > -1; i--){

            if(s[i] == ' ' && !flag) continue;
            else if(s[i] != ' '){
                count++;
                flag = 1;
            }
            else if(s[i] == ' ' && flag) return count;
        }

        return count;
    }
};