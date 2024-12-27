class Solution {
public:
    bool canMakeSubsequence(string str1, string str2){

        int p1 = 0, p2  = 0;

        while(p1 < str1.size() && p2 < str2.size()){
            
            if( ((str1[p1] + 1) % 26 == str2[p2] % 26) || str1[p1] == str2[p2]){
                p1++;
                p2++;
            }
            else p1++;
        }

        if(p2 >= str2.size()) return true;
        
        return false;
    }
};