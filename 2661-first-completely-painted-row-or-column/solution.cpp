class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        map<int, pair<int, int>> coord;

        int n = mat.size(), m = mat[0].size();

        vector<int> rows(n, m);
        vector<int> cols(m, n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                coord[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); i++){
            int r = coord[arr[i]].first;
            int c = coord[arr[i]].second;

            rows[r]--;
            cols[c]--;

            if(rows[r] <= 0 || cols[c] <= 0) return i; 
        }

        return arr.size() - 1;
    }
};