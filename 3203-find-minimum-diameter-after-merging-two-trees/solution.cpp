class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        unordered_map<int, vector<int>> graph1;
        unordered_map<int, vector<int>> graph2;

        int n1 = edges1.size() + 1,  n2 = edges2.size() + 1;

        int dia1 = INT_MIN, dia2 = INT_MIN;

        createGraph(graph1, edges1);
        createGraph(graph2, edges2);

        dia1 = bfs(graph1, n1, 0);
        dia2 = bfs(graph2, n2, 0);

        int center1 = (dia1 + 1) / 2;
        int center2 = (dia2 + 1) / 2;

        return max(max(dia2, center1 + center2 + 1), dia1);
    }

    void createGraph(unordered_map<int, vector<int>>& graph, vector<vector<int>>& edges){

        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    int bfs(unordered_map<int, vector<int>>& graph, int& sz, int start){

        queue<int> cache;

        vector<int> checked(sz, -1);

        int max_dist = -1;
        int farthest;

        checked[start] = -2;

        cache.push(start);

        while(!cache.empty()){

            int n = cache.size();

            while(n > 0){

                int curr = cache.front();

                cache.pop();

                farthest = curr;

                for(int& neighbor : graph[curr]){
                    if(checked[neighbor] == -1){
                        cache.push(neighbor);
                        checked[neighbor] = -2; // -2 means its visited.
                    }
                }

                n--;
            }
        }

        cache.push(farthest);
    
        checked[farthest] = -3;

        while(!cache.empty()){

            int n = cache.size();

            while(n > 0){

                int curr = cache.front();

                cache.pop();

                for(int& neighbor : graph[curr]){
                    if(checked[neighbor] == -2){
                        cache.push(neighbor);
                        checked[neighbor] = -3; // -3 means its visited.
                    }
                }

                n--;
            }
            max_dist++;
        }

        return max_dist;
    }
};