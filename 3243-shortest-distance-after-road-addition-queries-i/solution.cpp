class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    
        map<int, vector<int>> graph;
        vector<int> ans;

        int min_dist = n, target = n - 1;
        
        for(int i = 0; i < n - 1; i++){
            graph[i].push_back(i + 1);
        }

        for(const vector<int>& q : queries){
            graph[q[0]].push_back(q[1]);
            ans.push_back(bfs(graph, target));
        }

        return ans; 
    }

    int bfs(map<int, vector<int>>& graph, int& target){

        queue<int> q;

        int ans = 0;

        q.push(0);

        vector<bool> visited(target, false);

        while(!q.empty()){
            int n = q.size();
            
            while(n > 0){
                int curr = q.front();
                q.pop();

                if(curr == target) return ans;

                for(const int& n : graph[curr]){
                    if(!visited[n]){
                        visited[curr] = true;
                        q.push(n);
                    }
                }
                
                n--; 
            }
            ans++;
        }

        return ans;
    }
};