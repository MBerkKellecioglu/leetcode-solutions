class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){

        vector<int> parent;
        vector<int> ranks(edges.size() + 1, 1);

        for(int i = 0; i < edges.size() + 1; i++) parent.push_back(i);

        for(int i = 0; i < edges.size(); i++) if(!Union(parent, ranks, edges[i][0], edges[i][1])) return {edges[i][0], edges[i][1]};
        
        return {};     
    }

    int find(vector<int>& parent, int vertex){

        int root = parent[vertex];

        while(root != parent[root]) root = parent[root]; // Look for Search Compression // Can implement it faster // 

        return root;
    }


    bool Union(vector<int>& parent, vector<int>& ranks, int vertex1, int vertex2){

        int root1 = find(parent, vertex1);
        int root2 = find(parent, vertex2);

        if(root1 == root2) return false;

        if(ranks[root1] > ranks[root2]){
            parent[root2] = root1;
            ranks[root1] += ranks[root2];
        }
        else{
            parent[root1] = root2;
            ranks[root2] += ranks[root1];
        }

        return true;
    }
};