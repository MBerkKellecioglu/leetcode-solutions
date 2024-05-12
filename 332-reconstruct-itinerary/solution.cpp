class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string, vector<string>> graph;

        vector<string> sol;

        int n = tickets.size();

        for(int i = 0; i < tickets.size(); i++) graph[tickets[i][0]].push_back(tickets[i][1]);
        
        for(auto& elements : graph) sort(elements.second.begin(), elements.second.end());

        dfs(graph, sol, "JFK", n);

        reverse(sol.begin(), sol.end());

        return sol;
    }

    void dfs(map<string, vector<string>>& graph, vector<string>& sol, string curr, int& n){

        while(graph[curr].size() > 0){
            string tmp = graph[curr][0];
            graph[curr].erase(graph[curr].begin());
            dfs(graph, sol, tmp, n);
        }

        sol.push_back(curr);
    }

};