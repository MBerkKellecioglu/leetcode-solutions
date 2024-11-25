class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        if(board[1][2] == 0 && validate(board)) return 0;
        
        queue<vector<vector<int>>> q;
        map<vector<vector<int>>, bool> visited;
 
        visited[board] = 1;
        q.push(board);

        int count = 0;

        while(!q.empty()){
            int n = q.size();
            count++;

            while(n > 0){
                vector<vector<int>> curr_board = q.front();
                vector<vector<int>> tmp = curr_board;

                int x, y;

                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 3; j++){
                        if(!curr_board[i][j]){
                            y = i;
                            x = j;
                            break;
                        }
                    } 
                }

                q.pop();

                if(!y){
                    swap(tmp[y][x], tmp[y + 1][x]);
                    if(!tmp[1][2] && validate(tmp)) return count;
                     if(visited.find(tmp) == visited.end()){
                        q.push(tmp);
                        visited[tmp] = 1;
                    }
                    tmp = curr_board;
                }
                else{
                    swap(tmp[y][x], tmp[y - 1][x]);
                    if(!tmp[1][2] && validate(tmp)) return count;
                     if(visited.find(tmp) == visited.end()){
                        q.push(tmp);
                        visited[tmp] = 1;
                    }
                    tmp = curr_board;
                }

                if(x + 1 < 3){
                    swap(tmp[y][x], tmp[y][x + 1]);
                    if(!tmp[1][2] && validate(tmp)) return count;
                     if(visited.find(tmp) == visited.end()){
                        q.push(tmp);
                        visited[tmp] = 1;
                    }
                    tmp = curr_board;
                }

                if(x - 1 > -1){
                    swap(tmp[y][x], tmp[y][x - 1]);
                    if(visited.find(tmp) == visited.end()){
                        q.push(tmp);
                        visited[tmp] = 1;
                    }
                }

                n--;
            }
        }

        return -1;
    }

    bool validate(vector<vector<int>>& board){

        if(board[0][0] != 1) return false;
        if(board[0][1] != 2) return false;
        if(board[0][2] != 3) return false;
        if(board[1][0] != 4) return false;
        if(board[1][1] != 5) return false;

        return true;
    }
};