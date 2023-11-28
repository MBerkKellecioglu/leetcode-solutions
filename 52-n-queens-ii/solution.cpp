class Solution {
public:
    int row;
    int totalNQueens(int n) {
        row = n;
        int count = 0;

        vector<vector<int>> valid_pos(row, vector<int> (row, 1));

        recQueens(valid_pos, 0, count);

        return count;
    }

    void recQueens(vector<vector<int>> valid_pos, int level, int& count){
        if(level == row){
            count++;
            return;
        }

        for(int i = 0; i < row; i++){
            if(valid_pos[level][i]){
                recQueens(posValidator(valid_pos, i, level), level + 1, count);
            }
        }
    }

    vector<vector<int>> posValidator(vector<vector<int>> valid_pos, int& pos, int& level){
        int diagonal = 1;

        for(int i = level + 1; i < row; i++){
            if(pos + diagonal < row) valid_pos[i][pos + diagonal] = 0;
            valid_pos[i][pos] = 0;
            if(pos - diagonal > -1) valid_pos[i][pos - diagonal] = 0;
            diagonal++;
        }

        return valid_pos;
    }


    
};