class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<bool> sol(3, false);

        bool flag = 1;

        int count = 0;

        for(int i = 0; i < triplets.size(); i++){
            vector<bool> tmp = sol;
            for(int j = 0; j < 3; j++){ 
                if(triplets[i][j] == target[j]) tmp[j] = true;
                else if(triplets[i][j] > target[j]){
                    flag = 0;
                    break;
                } 
            }
            if(flag) sol = tmp;
            else flag = 1;
            if(sol[0] && sol[1] && sol[2]) return true;
        }

        for(int i = 0; i < 3; i++) if(!sol[i]) return false;

        return true;
    }
};