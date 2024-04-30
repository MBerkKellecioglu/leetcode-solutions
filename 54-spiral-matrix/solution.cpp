class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){

        int dir = 0, top = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

        vector<int> sol;

        // 0 means right, 1 means down, 2 means left, 3 means up // 

        while(top <= down && left <= right){

            if(dir == 0){
                for(int i = left; i <= right; i++){
                    sol.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top; i <= down; i++){
                    sol.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right; i >= left; i--){
                    sol.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(dir == 3){
                for(int i = down; i >= top; i--){
                    sol.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;   
        }

        return sol;
    }
};