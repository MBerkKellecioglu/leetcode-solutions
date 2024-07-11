class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int local_min = intervals[0][0], local_max = intervals[0][1];

        vector<vector<int>> sol;
        
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i + 1][0] > local_max){

                sol.push_back({local_min, local_max});

                local_min = intervals[i + 1][0];
                local_max = intervals[i + 1][1];
            }
            else{
                local_min = min(intervals[i + 1][0], local_min);
                local_max = max(intervals[i + 1][1], local_max);
            }
        }

        sol.push_back({local_min, local_max});
        
        return sol;
    }
};