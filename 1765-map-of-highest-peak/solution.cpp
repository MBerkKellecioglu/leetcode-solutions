class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size(), n = isWater[0].size();

        queue<pair<int,int>> cache;

        vector<vector<int>> ans(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j]){
                    cache.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!cache.empty()){

            int k = cache.size();

            while(k > 0){
                int r = cache.front().first;
                int c = cache.front().second;

                int curr_height = ans[r][c];

                cache.pop();

                if(r + 1 < m && ans[r + 1][c] == -1){
                    cache.push({r + 1, c});
                    ans[r + 1][c] = curr_height + 1;
                }

                if(r - 1 > -1 && ans[r - 1][c] == -1){
                    cache.push({r - 1, c});
                    ans[r - 1][c] = curr_height + 1;
                }
            
                if(c + 1 < n && ans[r][c + 1] == -1){
                    cache.push({r, c + 1});
                    ans[r][c + 1] = curr_height + 1;
                }
                
                if(c - 1 > -1 && ans[r][c - 1] == -1){
                    cache.push({r, c - 1});
                    ans[r][c - 1] = curr_height + 1;
                }

                k--;
            }

            cout << endl;
        }

        return ans;
    }
};