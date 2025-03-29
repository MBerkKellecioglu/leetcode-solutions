class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());

        int maxi = meetings[0][1], mini = meetings[0][0];

        for(int i = 1; i < meetings.size(); i++){

            if(meetings[i][0] <= maxi){
                maxi = max(meetings[i][1], maxi);
            }
            else{
                days -= (maxi - mini) + 1;

                mini = meetings[i][0];
                maxi = meetings[i][1];
            }
        }

        return days - ((maxi - mini) + 1);
    }
};