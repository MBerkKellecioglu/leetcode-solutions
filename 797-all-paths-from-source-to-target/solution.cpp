class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

       map<int, vector<int>> edges;
       vector<vector<int>> sol;

       vector<int> path;

       int n = graph.size() - 1;

       for(int i = 0; i < graph.size(); i++) edges[i] = graph[i];

       dfs(sol, edges, path, n, 0);

       return sol;
    }

    void dfs(vector<vector<int>>& sol, map<int, vector<int>>& edges, vector<int>& path, int& n, int curr){

        path.push_back(curr);

        if(curr == n){
            sol.push_back(path);
            path.pop_back();
            return;
        }

        for(auto neighbors : edges[curr]) dfs(sol, edges, path, n, neighbors);
        
        path.pop_back();
    }
};