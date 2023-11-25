class Solution {
public:
    bool exist(vector<vector<char>> board, string word){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(RecWord(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }

    bool RecWord(vector<vector<char>>& board, string& word, int count, int x, int y){

        if(count == word.size()) return true;

        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[count] != board[x][y]) return false;
        
        char tmp = board[x][y];
        board[x][y] = '!';

        bool result = RecWord(board, word, count + 1, x + 1, y) || RecWord(board, word, count + 1, x - 1, y) || RecWord(board, word, count + 1, x, y + 1) || RecWord(board, word, count + 1, x, y - 1);

        board[x][y] = tmp;

        return result;
    }
};