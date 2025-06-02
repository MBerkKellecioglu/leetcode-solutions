class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2){

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

        /* This vector is not for literal distance but rather for if the distance from inital node to current node is even or odd.
           We need this info for lets say our inital node (we start bfs from) has k even nodes. That means nodes that have odd
           distances from that inital node will have (lets say n is the total node count) n - k even nodes, and nodes that have 
           even distances from initial node will have same amount meaning k even nodes. This vector is only needed for tree1 -> Explained below */
        vector<int> dist1(n + 1, false);

        /* Same logic goes for tree2 but only difference is we only need the maximum amount of distance we can get. Only edge
           case is when there is only one node we cant check which is higher because there is no other node that we can connect
           our tree1 nodes to. */
        int odd_count = bfs(tree2, dist1, 0, 1);

        if(m != 0){
            odd_count = max(odd_count , (m + 1 - odd_count));
        }

        int even_count = bfs(tree1, dist1, 0, 0);

        for(int i = 0; i < edges1.size() + 1; i++){
            if(dist1[i]) ans[i] = (n + 1 - even_count) + odd_count;
            else ans[i] = even_count + odd_count;
        }

        return ans;
    }

    int bfs(vector<vector<int>>& tree, vector<int>& dist, int start, int flag){
        
        // first is current second is parent
        queue<pair<int, int>> q;

        int count = 0, level = 0;

        q.push({start, -1});

        while(!q.empty()){

            int sz = q.size();

            while(sz > 0){
                pair<int,int> curr = q.front();
                q.pop();

                count += (flag) ? level % 2 : !(level % 2);

                if(!flag) dist[curr.first] = level % 2;

                for(int& neighbor : tree[curr.first]){
                    if(curr.second != neighbor) q.push({neighbor, curr.first});
                }

                sz--;
            }

            level++;
        }
        return count;
    }
};