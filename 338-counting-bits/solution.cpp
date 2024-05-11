class Solution {
public:
    vector<int> countBits(int n){

        vector<int> memo(n + 1, 0);

        int two_expo = 0;


        for(int i = 1; i < n + 1; i++){
            if(i == pow(2, two_expo + 1)){
                memo[i] = 1;
                two_expo++;
                continue;
            }

            memo[i] = memo[i - pow(2, two_expo)] + 1;

        }

        return memo;
    }
};