class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){

        queue<pair<pair<int,int>, int>> cache;

        cache.push({{entrance[0], entrance[1]}, 0});

        maze[entrance[0]][entrance[1]] = '+';

        while(!cache.empty()){
            int x = cache.front().first.first;
            int y = cache.front().first.second;
            int dist = cache.front().second;

            if(checkValid(x, y, maze.size(), maze[0].size()) && (x != entrance[0] || y != entrance[1])) return dist;
            
            cache.pop();

            if(x + 1 < maze.size() && maze[x + 1][y] == '.'){
                maze[x + 1][y] = '+';
                cache.push({{x + 1, y}, dist + 1});
            }
            if(x - 1 > -1 && maze[x - 1][y] == '.'){
                maze[x - 1][y] = '+';
                cache.push({{x - 1, y}, dist + 1});
            }
            if(y + 1 < maze[0].size() && maze[x][y + 1] == '.'){
                maze[x][y + 1] = '+';
                cache.push({{x, y + 1}, dist + 1});
            }
            if(y - 1 > -1 && maze[x][y - 1] == '.'){
                maze[x][y - 1] = '+';
                cache.push({{x, y - 1}, dist + 1});
            }
        }
        
        return -1;
    }

    bool checkValid(int x, int y, int row, int col){
        if(x == 0 || x == row - 1 || y == 0 || y == col - 1) return true;

        return false;
    }
};