class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        int y = 0, x = m - 1;


        while(y < n && x > -1){
            if(matrix[y][x] < target){
                y++;
            }
            else if(matrix[y][x] > target){
                x--;
            }
            else return true;
        }

        return false;
    }
};