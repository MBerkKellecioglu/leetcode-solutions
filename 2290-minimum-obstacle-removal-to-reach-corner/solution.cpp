struct CompareBySecond {
    bool operator()(const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b) {
        return a.second > b.second; 
    }
};


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        int n = grid.size() - 1, m = grid[0].size() - 1;
        
        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, CompareBySecond> minHeap;

        minHeap.push({{0,0}, 0});
        grid[0][0] = 2;

        // 2 means its visited

        while(!minHeap.empty()){
            
            int k = minHeap.size();

            while(k > 0){
                int y = minHeap.top().first.first;
                int x = minHeap.top().first.second;

                int obst = minHeap.top().second;

                minHeap.pop();

                if(y == n && x == m) return obst;

                if(y < n && grid[y + 1][x] != 2){
                    minHeap.push({{y + 1, x}, obst + grid[y + 1][x]});
                    grid[y + 1][x] = 2;
                }

                if(x < m && grid[y][x + 1] != 2){
                    minHeap.push({{y, x + 1}, obst + grid[y][x + 1]});
                    grid[y][x + 1] = 2;
                }

                if(y > 0 && grid[y - 1][x] != 2){
                    minHeap.push({{y - 1, x}, obst + grid[y - 1][x]});
                    grid[y - 1][x] = 2;
                }

                if(x > 0 && grid[y][x - 1] != 2){
                    minHeap.push({{y, x - 1}, obst + grid[y][x - 1]});
                    grid[y][x - 1] = 2;
                }

                k--;
            }
        }

        return 0;
    }
};