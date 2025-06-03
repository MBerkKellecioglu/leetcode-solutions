class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        queue<int> q;

        int count = 0;

        bool checked[1001];
        bool available[1001];

        for(int i = 0; i < 1001; i++){
            checked[i] = false;
            available[i] = false;
        }

        for(int box : initialBoxes) q.push(box);
        
        while(!q.empty()){
            
            int sz = q.size();

            while(sz > 0){
                int curr = q.front();
                q.pop();
                
                available[curr] = true;

                if(!checked[curr] && status[curr]){
                    count += candies[curr];
                    checked[curr] = true;

                    for(int key : keys[curr]){
                        status[key] = 1;
                        if(available[key]) q.push(key);
                    }
                    
                    for(int box : containedBoxes[curr]) q.push(box);
                }
                sz--;
            }
        }

        return count;
    }
};