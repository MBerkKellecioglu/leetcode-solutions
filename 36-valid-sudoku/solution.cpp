class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            std::vector<int> sudo1(12,0);
            std::vector<int> sudo2(12,0);
            for(int j = 0 ; j < 9; j++){
                int square1 = board[i][j] - '0' + 2;
                int square2 = board[j][i] - '0' + 2;
                sudo1[square1]++;
                sudo2[square2]++;
                if(square1 && sudo1[square1] > 1) return false;
                if(square2 && sudo2[square2] > 1) return false;
            }
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+= 3){
                std::vector<int> sudo1(12,0);
                for(int k = i; k < i + 3; k++){
                    for(int l = j; l < j + 3; l++){
                        sudo1[board[k][l] - '0' + 2]++;
                        if(board[k][l] - '0' + 2 != 0 && sudo1[board[k][l] - '0' + 2] > 1) return false;
                    }
                }    
            }  
        }
        return true;
    }
};