class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int p1 = 0, p2 = 0;

        string sol = "";

        while(p1 < word1.size() && p2 < word2.size()){
            sol += word1[p1];
            sol += word2[p2];

            p1++;
            p2++;
        }

        while(p1 < word1.size()){
            sol += word1[p1];
            p1++;
        }
        while(p2 < word2.size()){
            sol += word2[p2];
            p2++;
        }

        return sol;
    }
};