class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()) return false;
        
        map<char, int> freq1;
        map<char, int> freq2;

        vector<int> ans1;
        vector<int> ans2;

        int n = word1.size(), count = 0;

        for(int i = 0; i < n; i++){
            freq1[word1[i]]++;
            freq2[word2[i]]++;
        }

        for(auto elements : freq1){
            if(freq2.find(elements.first) != freq2.end()) count++;
            ans1.push_back(elements.second);
        }

        if(count != freq2.size()){
            return false;
        }

        for(auto elements : freq2) ans2.push_back(elements.second);

        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());

        return ans1 == ans2;
    }
};