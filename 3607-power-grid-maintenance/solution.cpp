class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries){

        map<int, vector<int>> graph;

        vector<vector<int>> online(c + 1, vector<int>(2, 0));

        map<int, priority_queue <int, vector<int>, greater<int>>>components;

        vector<int> ans;

        for(auto c : connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        for(int i = 1; i <= c; i++){
            if(!online[i][1]) dfs(graph, components, components.size(), online, i);
        }

        int count = 0;

        for(auto q : queries){
            if(q[0] == 2){
                online[q[1]][1] = 0;
            }
            else{
                if(online[q[1]][1] == 1) ans.push_back(q[1]);
                else{
                    int c_id = online[q[1]][0];
                    while(online[components[c_id].top()][1] == 0 && components[c_id].size() > 0){
                        components[c_id].pop();
                    }

                    if(components[c_id].size() > 0) ans.push_back(components[c_id].top());
                    else ans.push_back(-1);
                }
            }
        }

        return ans;
    }

    void dfs(map<int, vector<int>>& graph, map<int, priority_queue <int, vector<int>, greater<int>> >& components, int c_id, vector<vector<int>>& online, int station){
        
        components[c_id].push(station);

        online[station][0] = c_id;

        online[station][1] = 1;

        for(auto s : graph[station]){
            if(!online[s][1]){
                online[s][1] = 1;
                dfs(graph, components, c_id, online, s);
            }
        }

        return;
    }
};