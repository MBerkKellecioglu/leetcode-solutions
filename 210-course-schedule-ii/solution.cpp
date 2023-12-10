class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {

        vector<int> degree(numCourses, 0);

        map<int, vector<int>> adj;
        vector<int> topological;
        vector<int> checked_vals(numCourses, 0);

        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            degree[pre[i][0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            cout << degree[i] << " ";
        }

        queue<int> kahn;

        for(int i = 0; i < numCourses; i++) if(degree[i] == 0) kahn.push(i);;
        
        while(!kahn.empty()){
            int q_size = kahn.size();

            for(int i = 0; i < q_size; i++){
                int vertex = kahn.front();
                kahn.pop();
                topological.push_back(vertex);
                if(checked_vals[vertex]) return {};
                checked_vals[vertex] = 1;

                vector<int> single_pre = adj[vertex];

                for(auto& nums : single_pre){
                    degree[nums]--;
                    if(!degree[nums]){
                        cout << "hi";
                        kahn.push(nums);
                    }
                }
            }
        }
        if(find(checked_vals.begin(), checked_vals.end(), 0) != checked_vals.end()) return {};
        return topological;
    }
};