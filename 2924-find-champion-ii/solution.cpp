class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> weak(n, 0);

        int ans = -1;

        for(const vector<int>& edge : edges){
            weak[edge[1]] = 1;
        }

        for(int i = 0; i < n; i++){
            if(!weak[i]){
                if(ans == -1) ans = i;
                else return -1;
            }
        }

        return ans;
    }
};