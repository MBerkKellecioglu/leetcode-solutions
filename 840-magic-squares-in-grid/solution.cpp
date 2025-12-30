class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        if(grid.size() * grid[0].size() < 9) return 0;

        int sol = 0;

        for(int i = 0; i < grid.size() - 2; i++){
            for(int j = 0; j < grid[0].size() - 2; j++){
                sol += validate(grid, i, j);
            }
        }

        return sol;
    }

    bool validate(vector<vector<int>>& grid, int& x, int& y){

        int sum = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2], tmp;
        int sum2 = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];

        if(sum != sum2) return 0;
    
        vector<int> nums(9, 1);

        for(int i = y; i < y + 3; i++){
            for(int j = x; j < x + 3; j++){
                tmp += grid[j][i];
                if(grid[j][i] - 1 < 9 && grid[j][i] - 1 > -1) nums[grid[j][i] - 1]--;
            }
            if(tmp != sum) return 0;
            else tmp = 0;
        }

        for(auto freq : nums) if(freq != 0) return 0;
        
        tmp = 0;

        for(int i = x; i < x + 3; i++){
            for(int j = y; j < y + 3; j++){
                tmp += grid[i][j];
            }
            if(tmp != sum) return 0;
            else tmp = 0;
        }

        return 1;
    }
};