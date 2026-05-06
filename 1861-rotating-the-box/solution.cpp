class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int rows = box.size(), cols = box[0].size(), stones = 0;

        vector<vector<char>> ans(cols, vector<char>(rows, '.'));

        for(int i = rows - 1; i > -1; i--){
            stones = 0;
            int j = cols - 1;

            int floor = cols - 1;

            for(j; j > -1; j--){
                if(box[i][j] == '#') stones++;
                else if(box[i][j] == '*'){
                    ans[j][rows - (i + 1)] = '*';
                    if(stones) fill(ans, floor, rows - (i + 1), stones);
                    floor = j - 1;
                    stones = 0;
                }
            }

            if(stones) fill(ans, floor, rows - (i + 1), stones);
        }

        return ans;
    }


    void fill(vector<vector<char>>& ans, int r, int c, int s){

        for(s; s > 0; s--){
            if(r > -1) ans[r][c] = '#';
            r--;
        }
    }
};