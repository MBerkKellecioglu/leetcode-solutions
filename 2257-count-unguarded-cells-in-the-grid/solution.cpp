class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        // 2 means guard, 3 means wall, 1 means guarded, 0 means unguarded 
        vector<vector<int>> prison(m, vector<int>(n, 0));

        int count = 0;

        for(const vector<int>& wall : walls){
            prison[wall[0]][wall[1]] = 3;
            count++;
        }

        for(vector<int>& guard : guards){
            prison[guard[0]][guard[1]] = 2;
            count++;
        }

         for(vector<int>& guard : guards){
            mark(prison, guard, count);
        }

        return (m * n) - count;
    }

    void mark(vector<vector<int>>& prison, vector<int>& guard, int& count){
        
        int y = guard[0], x = guard[1], m = prison.size(), n = prison[0].size();

        while(x + 1 < n){
            if(!prison[y][x + 1]){
                prison[y][x + 1] = 1;
                count++;
            }
            else if(prison[y][x + 1] != 1) break;

            x++;
        }

        x = guard[1];

        while(x - 1 > -1){
            if(!prison[y][x - 1]){
                prison[y][x - 1] = 1;
                count++;
            }
            else if(prison[y][x - 1] != 1) break;

            x--;
        }

        x = guard[1];

        while(y + 1 < m){
            if(!prison[y + 1][x]){
                prison[y + 1][x] = 1;
                count++;
            }
            else if(prison[y + 1][x] != 1) break;

            y++;
        }

        y = guard[0];

        while(y - 1 > -1){
            if(!prison[y - 1][x]){
                prison[y - 1][x] = 1;
                count++;
            }
            else if(prison[y - 1][x] != 1) break;
            
            y--;
        }
    }
};