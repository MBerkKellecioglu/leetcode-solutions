class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> spiral(n, vector<int>(n, 0));

        int x = 0, y = 0, count = 2;
        
        spiral[x][y] = 1;

        // 0 means right, 1 means down, 2 means left, 3 means up;
        int dir = 0;

        while(count < (n*n) + 1){
            while(checkIfValid(spiral, x, y, dir, n)){
                spiral[x][y] = count;
                count++;
            }
            dir++;
            dir %= 4;
        }

        return spiral;
    }

    bool checkIfValid(vector<vector<int>>& spiral, int& x, int& y, int& dir, int& n){

        if(dir == 0){
            if(y + 1 >= n || spiral[x][y + 1] != 0) return false;
            y++;
            return true;
        }
        else if(dir == 1){
            if(x + 1 >= n || spiral[x + 1][y] != 0) return false;
            x++;
            return true;
        }
        else if(dir == 2){
            if(y - 1 < 0 || spiral[x][y - 1] != 0) return false;
            y--;
            return true;
        }
        else if(dir == 3){
            if(x - 1 < 0 || spiral[x - 1][y] != 0) return false;
            x--;
            return true;
        }

        return true;
    }
};