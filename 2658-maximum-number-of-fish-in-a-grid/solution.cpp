class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] > 0){
                    ans = max(ans, BFS(grid, {i, j}));
                }
            }
        }

        return ans;
    }

    int BFS(vector<vector<int>>& grid, pair<int, int> coord){

        queue<pair<int, int>> q;

        int sum = 0, m = grid.size(), n = grid[0].size();

        q.push(coord);

        while(!q.empty()){

            int sz = q.size();

            while(sz > 0){
                pair<int, int> curr = q.front();

                q.pop();

                sum += grid[curr.first][curr.second];

                grid[curr.first][curr.second] = 0;

                if(curr.first + 1 < m && grid[curr.first + 1][curr.second] > 0){
                    q.push({curr.first + 1, curr.second});
                }

                if(curr.first - 1 > -1 && grid[curr.first - 1][curr.second] > 0){
                    q.push({curr.first - 1, curr.second});
                }

                if(curr.second - 1 > -1 && grid[curr.first][curr.second - 1] > 0){
                    q.push({curr.first, curr.second - 1});
                }
                
                if(curr.second + 1 < n && grid[curr.first][curr.second + 1] > 0){
                    q.push({curr.first, curr.second + 1});
                }

                sz--;
            }   
        }

        return sum;
    }
};