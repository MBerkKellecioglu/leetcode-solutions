class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(edges.size() == 0){
            vector<int> sol;

            for(int i = 0; i < n; i++){
                sol.push_back(i);
            }
            return sol;
        }

        vector<int> indegree(n, 0);

        vector<int> adj[n];

        vector<int> sol;

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> cache;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 1) cache.push(i);
        }

        while(n > 2){
            int q_size = cache.size();
            n -= q_size;
            
            for(int i = 0; i < q_size; i++){
                int curr = cache.front();
                cache.pop();

                vector<int> neighbors = adj[curr];

                for(auto neighbor : neighbors){
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 1) cache.push(neighbor);
                }
            }
        }

        while(cache.size()){
            sol.push_back(int(cache.front()) );
            cache.pop();
        }
        return sol;
    }

};