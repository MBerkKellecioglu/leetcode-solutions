class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {

        map<int, vector<int>> adj;

        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        vector<bool> ans(queries.size(), false);

        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        for(int i = 0; i < numCourses; i++){
            bfs(adj, reachable, i, numCourses);
        }

        for(int i = 0 ; i < queries.size(); i++){
            ans[i] = reachable[queries[i][0]][queries[i][1]];
        }

        return ans;
    }

    void bfs(map<int, vector<int>> adj, vector<vector<bool>>& reachable, int start, int& sz){

        vector<bool> checked(sz, false);

        reachable[start][start] = true;

        queue<int> q;
        
        q.push(start);

        while(!q.empty()){
            int n = q.size();

            while(n > 0){

                int curr = q.front();

                vector<int> tmp = adj[curr];

                q.pop();

                for(int& neighbors : tmp){
                    if(!checked[neighbors]){
                        q.push(neighbors);
                        checked[neighbors] = true;
                        reachable[start][neighbors] = true;
                    }
                }

                n--;
            }
        }
    }
};