class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int ans = 1;
        
        for(int i = 0; i < points.size(); i++){
            int py1 = points[i][0];
            int px1 = points[i][1];
            for(int j = i + 1; j < points.size(); j++){
                int py2 = points[j][0];
                int px2 = points[j][1];

                double slope = 0;
                bool flag = false;

                if((px2 - px1) == 0) flag = true;
                else slope = double(py2 - py1) / double(px2 - px1);

                int align = 2;

                for(int k = j + 1; k < points.size(); k++){
                    int py3 = points[k][0];
                    int px3 = points[k][1];

                    double tmp = 0;

                    if(flag){
                        if(px2 - px3 == 0) align++;
                        continue;
                    }
                    else tmp = double(py2 - py3) / double(px2 - px3);

                    if(slope == tmp) align++;
                }
                ans = max(ans, align);
            }
        }

        return ans;
    }
};