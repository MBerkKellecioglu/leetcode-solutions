class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();

        int collision = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(j == 0) collision = 0;
                    else matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0){
            for(int j = n - 1; j > 0; j--) matrix[0][j] = 0;
        }

        if(collision == 0){
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }


    }
};