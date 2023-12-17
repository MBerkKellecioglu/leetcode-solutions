class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words){

        map<string, int> mp;
        vector<int> sol;
        string word;

        int r = words[0].size();
        int sub_size = r * words.size();

        if(sub_size > s.size()) return {};

        for(auto word : words) mp[word]++;

        word = s.substr(0, r);
        r--;

        while(r + sub_size - words[0].size() <= s.size()){
            if(mp[word] > 0) if(getOtherWords(mp, s, word, r + 1, words.size() - 1)) sol.push_back(r - words[0].size() + 1);
            word.erase(word.begin());
            r++;
            word += string(1, s[r]);
        }
        return sol;
    }

    bool getOtherWords(map<string, int> mp, string& s, string word, int start, int count){
        mp[word]--;

        cout << start << " " << word << endl;

        while(start + word.size() <= s.size() && count > 0){
            string tmp = s.substr(start, word.size());
            if(mp[tmp] <= 0){
                return false;
            }
            else mp[tmp]--;
            start += word.size();
            count--;
        }
        if(count > 0) return false;

        return true;
    }
};