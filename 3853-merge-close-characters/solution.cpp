class Solution {
public:
    string mergeCharacters(string s, int k){
        
        map<char, int> ind;

        int i = 0;

        while (i < s.size()){
            char c = s[i];

            if(ind.contains(c)){
                int prev = ind[c];

                if(i - prev > k){
                    ind[c] = i;
                }
                else{
                    s.erase(i,1);
                    i--;
                }
            }
            else ind[c] = i;

            i++;
        }

        return s;
    }
};