class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 1001); 
        vector<vector<int>> graph(n);
        int minLength = 1001;
        
        for (vector<int> & edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (minLength == 3) break;
            if (visited[i] == 1001) dfs(graph, visited, i, -1, 0, minLength);
        }
                
        return minLength == 1001 ? -1 : minLength;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& visited, int vertice, int parent, int length, int& cycle){

        // 3 is the shortest possible cycle. Do not proccess search if we already found such cycle
        if (cycle == 3){ 
            return;
        }

        visited[vertice] = length++;
        for (int next : graph[vertice]) {
            if (next == parent)
                continue;
            if (visited[next] > length) // This is the line that does the whole trick //

                /* It looks like what it does is that if you are traversing a path it ensures that you dont 
                run into already visited nodes but with a little difference. It ensures that you dont run into nodes 
                that are already visited ON THAT EXACT PATH you took to get there. */

                /* That means if you are already visited a node before, instead of not going to that node it detects if 
                we visited it on same path we took to go to that node, if not, it goes to the node.*/

                /* To fully understand how that if statment ensures what i mentioned uptop draw the test case's graph 
                that i will give here, and trace it. Tracing it will not be a big problem dont worry.*/

                // Test Case: n = 8, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[0,7],[0,6],[5,7],[5,6]] //

                dfs(graph, visited, next, vertice, length, cycle);

            if ((length - visited[next]) > 2){
                cycle = min(cycle, (length - visited[next]));
            }
        }
    }
};