class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int ind = 0;

        string ans = "";

        for(int i = 0; i < spaces.size(); i++){
            ans += s.substr(ind, spaces[i] - ind);
            ans += " ";

            ind = spaces[i];
        }

        ans += s.substr(ind, s.size() - ind);

        return ans;
    }
};