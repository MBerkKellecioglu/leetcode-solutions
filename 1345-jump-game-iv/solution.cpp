class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size(), ans = -1;

        unordered_map<int, vector<int>> indexes;

        vector<bool> checked(n, false);

        for (int i = 0; i < n; i++){
            indexes[arr[i]].push_back(i);
        }

        queue<int> q;

        q.push(0);

        while (q.size()){
            int sz = q.size();
            ans += 1;

            while(sz--){
                int curr = q.front();
                q.pop();
                
                if (curr == n - 1) return ans;
                
                int curr_num = arr[curr];

                checked[curr] = true;

                if ((curr + 1 < n) && !checked[curr + 1]){
                    checked[curr + 1]= true;
                    q.push(curr + 1);
                }

                if ((curr - 1 >= 0) && !checked[curr - 1]){
                    checked[curr - 1]= true;
                    q.push(curr - 1);
                }

                for(int ind : indexes[curr_num]){
                    if (!checked[ind]){
                        checked[ind] = true;
                        q.push(ind);
                    }
                }

                indexes.erase(curr_num);
            }
        }

        return ans;
    }
};