class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rCurr, int cCurr) {
        
        vector<vector<int>> sol;

        int total = rows * cols, x_cap = 1, y_cap = 1, dir = 0;

        // 0 means right, 1 means down, 2 means left, 3 means up //

        sol.push_back({rCurr, cCurr});

        while(sol.size() < total){
            if(dir == 0){
                traverse(sol, x_cap, rCurr, cCurr, 1, 0, rows, cols);
                x_cap++;
                dir++;
            }
            else if(dir == 1){
                traverse(sol, y_cap, rCurr, cCurr, 0, 1, rows, cols);
                y_cap++;
                dir++;
            }
            else if(dir == 2){
                traverse(sol, x_cap, rCurr, cCurr, -1, 0, rows, cols);
                x_cap++;
                dir++;
            }
            else if(dir == 3){
                traverse(sol, y_cap, rCurr, cCurr, 0, -1, rows, cols);
                y_cap++;
                dir++;
            }

            dir %= 4;
        }

        return sol;
    }

    void traverse(vector<vector<int>>& sol, int& cap, int& rCurr, int &cCurr, int x_inc, int y_inc, int& rows, int& cols){
        
        int total_dist = 0;

        while(total_dist < cap){
            rCurr += y_inc;
            cCurr += x_inc;

            if(rCurr > -1 && rCurr < rows && cCurr < cols && cCurr > -1) sol.push_back({rCurr, cCurr});
            
            total_dist++;
        }
    }
};