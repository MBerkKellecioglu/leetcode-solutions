class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        int freq[26];

        priority_queue<char> maxHeap;

        char prev = ' ';

        string ans = "";

        for(char c : s){
            freq[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0) maxHeap.push(i + 'a');
        }

        while(!maxHeap.empty()){
            char curr = maxHeap.top();
            maxHeap.pop();

            int repeat;

            // space character is lesser than letters in ASCII table
            if(prev < curr){
                repeat = (freq[curr - 'a'] > repeatLimit) ? repeatLimit : freq[curr - 'a'];
            }
            else repeat = 1;

            for(int i = 0; i < repeat; i++) ans += string(1, curr);

            freq[curr - 'a'] -= repeat;

            if(prev != ' '){
                maxHeap.push(prev);
            }

            if(freq[curr - 'a'] != 0) prev = curr;
            else prev = ' ';
        }

        return ans;
    }
};