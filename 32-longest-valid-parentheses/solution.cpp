class Solution {
public:
    int longestValidParentheses(string s){
        int longest_seq = 0, longest_seq2 = 0, seq = 0, count = 0, count2 = 0, seq2 = 0, j = s.size() - 1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')count++;
            else{
                if(count != 0){
                    seq++;
                    count--;
                    if(count == 0) longest_seq = max(longest_seq, seq);
                }
                else seq = 0;
            }
            if(s[j] == ')') count2++;
            else{
                if(count2 != 0){
                    seq2++;
                    count2--;
                    if(count2 == 0) longest_seq2 = max(longest_seq2, seq2);
                }
                else seq2 = 0;
            }
            j--;
        }

        return max(longest_seq, longest_seq2) * 2;
    }
};