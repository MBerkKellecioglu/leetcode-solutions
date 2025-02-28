

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int, vector<int>> color_ball;
        unordered_map<int, int> ball_color;

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++){
            
            int ball = queries[i][0];
            int color = queries[i][1];

            int old_color = ball_color[ball];

            if(old_color != 0){
                vector<int>& balls = color_ball[old_color];

                auto it = find(balls.begin(), balls.end(), old_color);

                balls.erase(it);

                if(balls.empty()){
                    color_ball.erase(old_color);
                }
            }

            ball_color[ball] = color;

            color_ball[color].push_back(ball);

            ans.push_back(color_ball.size());
        }

        return ans;
    }
};