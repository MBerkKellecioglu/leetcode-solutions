class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum){

        int sum = 0, curr = 1, ans = 0;

        unordered_map<int, bool> banned;

        for(int& num : b){
            banned[num] = true;
        }

        while(curr <= n){

            if(banned.find(curr) != banned.end()){
                curr++;
                continue;
            }
            else{
                if(curr + sum <= maxSum){
                    sum += curr;
                }
                else break;

                curr++;
            }
            
            ans++;
        }

        return ans;   
    }
};