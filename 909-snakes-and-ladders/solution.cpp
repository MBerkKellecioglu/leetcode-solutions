class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size(), ans = 0;
        
        queue<int> q;

        vector<bool> checked((n*n) + 1, 0);

        q.push(1);

        while(!q.empty()){

            int sz = q.size();

            while(sz > 0){
                int curr = q.front();
                q.pop();
                sz--;

                checked[curr] = 1;

                if(curr == n*n) return ans;

                for(int i = 1; i < 7; i++){
                    int next = min(curr + i, n*n);

                    //if(checked[next]) continue;

                    pair<int, int> coor = convert(next, n);

                    int converted = board[coor.first][coor.second];
                   
                    if(converted != -1 && !checked[converted]){
                        checked[converted] = 1;
                        q.push(converted);
                    }
                    else if(converted == -1 && !checked[next]){
                        checked[next] = 1;
                        q.push(next); 
                    }
                }
            }
            
            ans++;
        }

        return -1;
    }

    pair<int, int> convert(int num, int n){

        int i = n - ceil((float(num) / float(n) )), j = 0;

        bool left_to_right = (n % 2) ? !(i % 2) : (i % 2) ;

        j = (left_to_right) ? num - ( ((n - i - 1) * n) + 1) : ((n - i) * n) - num;

        return {i, j};
    }
};