struct CompareBySecond {
    bool operator()(const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b) {
        return a.second > b.second; 
    }
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size() - 1, m = grid[0].size() - 1;
        
        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, CompareBySecond> minHeap;

        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        minHeap.push({{0,0}, 0});

        grid[0][0] = -1;

        while(!minHeap.empty()){
            
            int k = minHeap.size();

            while(k > 0){
                int y = minHeap.top().first.first;
                int x = minHeap.top().first.second;

                int time = minHeap.top().second;

                int future = time;

                minHeap.pop();

                if(y == n && x == m) return time;

                if(y < n && grid[y + 1][x] != -1){
                    if(time >= grid[y + 1][x]) future = time + 1;
                    else future = ((grid[y + 1][x] - time) % 2 == 0) ? grid[y + 1][x] + 1 : grid[y + 1][x];
                    
                    minHeap.push({{y + 1, x}, future});
                    grid[y + 1][x] = -1;
                }

                if(x < m && grid[y][x + 1] != -1){
                    if(time >= grid[y][x + 1]) future = time + 1;
                    else future = ((grid[y][x + 1] - time) % 2 == 0) ? grid[y][x + 1] + 1 : grid[y][x + 1];
                    
                    minHeap.push({{y, x + 1}, future});
                    grid[y][x + 1] = -1;
                }

                if(y > 0 && grid[y - 1][x] != -1){
                    if(time >= grid[y - 1][x]) future = time + 1;
                    else future = ((grid[y - 1][x] - time) % 2 == 0) ? grid[y - 1][x] + 1 : grid[y - 1][x];
                    
                    minHeap.push({{y - 1, x}, future});
                    grid[y - 1][x] = -1;
                }

                if(x > 0 && grid[y][x - 1] != -1){
                    if(time >= grid[y][x - 1]) future = time + 1;
                    else future = ((grid[y][x - 1] - time) % 2 == 0) ? grid[y][x - 1] + 1 : grid[y][x - 1];
                    
                    minHeap.push({{y, x - 1}, future});
                    grid[y][x - 1] = -1;
                }

                k--;
            }
        }

        return -1;
    }  
};