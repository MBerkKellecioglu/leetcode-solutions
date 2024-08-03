class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int l = 0, r = intervals.size() - 1, ind = -1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(mid + 1 < intervals.size() && intervals[mid][0] <= newInterval[0] && intervals[mid + 1][0] >= newInterval[0]){
                intervals.insert(intervals.begin() + mid + 1, newInterval);
                ind = mid;
                break;
            }
            else if(intervals[mid][0] <= newInterval[0]) l++;
            else r--;
        }

        if(ind == -1){
            if(intervals.size() == 0 || intervals[intervals.size() - 1][0] <= newInterval[0]){
                intervals.push_back(newInterval);
            }
            else{
                intervals.insert(intervals.begin(), newInterval);
            }
        }

        int local_min = intervals[0][0], local_max = intervals[0][1];

        vector<vector<int>> sol;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > local_max){
                sol.push_back({local_min, local_max});

                local_max = intervals[i][1];
                local_min = intervals[i][0];
            }
            else{
                local_min = min(intervals[i][0], local_min);
                local_max = max(intervals[i][1], local_max);
            } 
        }

        sol.push_back({local_min, local_max});

        return sol;
    }
};