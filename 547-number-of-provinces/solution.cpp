class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected){

        vector<int>checked(isConnected.size(), 0);
        int count = 0;

        for(int i = 0; i < checked.size(); i++){
            if(!checked[i]){
                count++;
                checked[i] = 1;
                dfs(isConnected, checked, i);
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>&checked, int city){

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[city][i] && !checked[i]){
                checked[i] = 1;
                dfs(isConnected, checked, i);
            }
        }
    }
};