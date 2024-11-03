class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());

        int local_max = points[0][1], ans = 0;

        for(int i = 1; i < points.size(); i++){
            if(local_max >= points[i][0]){
                local_max = min(local_max, points[i][1]);
                ans++;
            }
            else local_max = points[i][1];
        }

        return points.size() - ans;
    }
};