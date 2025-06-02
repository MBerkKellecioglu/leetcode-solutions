class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k){

        int n = edges1.size(), m = edges2.size();

        vector<vector<int>> tree1(n + 1, vector<int>());
        vector<vector<int>> tree2(m + 1, vector<int>());

        int maxi = INT_MIN;

        vector<int> ans(n + 1, 0);

        for(auto edge : edges1){
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }

        for(auto edge : edges2){
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < edges2.size() + 1; i++){
            maxi = max(bfs(tree2, i, k, m), maxi);
        }

        for(int i = 0; i < edges1.size() + 1; i++){
            ans[i] = bfs(tree1, i, k + 1, n) + maxi;
        }

        return ans;
    }

    int bfs(vector<vector<int>>& tree, int& start, int level, int n){

        queue<int> q;

        vector<bool> checked(n + 1, false); // Instead of checked array to optimize use prev logic

        int count = 0;

        q.push(start);

        while(!q.empty()){

            int sz = q.size();

            if(level <= 0) break;

            while(sz > 0){
                int curr = q.front();
                q.pop();
                count++;

                checked[curr] = true;

                vector<int> neighbors = tree[curr];

                for(int neighbor : neighbors){
                    if(!checked[neighbor]) q.push(neighbor);
                }

                sz--;
            }

            level--;
        }
        return count;
    }
};