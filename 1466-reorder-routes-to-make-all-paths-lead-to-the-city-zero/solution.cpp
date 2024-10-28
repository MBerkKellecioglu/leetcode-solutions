class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> graph(n);

        int ans = 0;

        // 1 means its c[0] -> c[1], 0 means its reversed
        for(vector<int>& c : connections){
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }

        dfs(graph, -1, 0, ans);

        return ans;
    }

    void dfs(vector<vector<pair<int,int>>>& graph, int prev, int curr, int& ans){

        for(pair<int,int>& neighbor : graph[curr]){
            if(prev == neighbor.first) continue;

            if(neighbor.second) ans++;
            dfs(graph, curr, neighbor.first, ans);
        }

        return;
    }
};