class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size();

        int ans = 0;

        vector<pair<int,int>> cons;

        for(int i = 0; i < n - 1; i++){
            int totalTime = neededTime[i];
            int maxTime = totalTime;

            int start = i;

            while(colors[i] == colors[i + 1]){
                totalTime += neededTime[i + 1];
                maxTime = max(maxTime, neededTime[i + 1]);
                i++;
            }

            if(start != i){
                ans += totalTime - maxTime;
            }

        }

        return ans;
    }
};