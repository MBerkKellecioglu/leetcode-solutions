class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points){
        
        int ans = 0;

        // I thought we could only move diagonally with positive slope but thats not the case
        
        // Since We can move in 8 directions we only need max distance between points (x - x1) or (y - y1)

        for(int i = 1; i < points.size(); i++){
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            ans += max(dx, dy);
        }

        return ans;
    }
};