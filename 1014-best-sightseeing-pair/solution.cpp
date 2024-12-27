class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values){

        int f_ind = 0, f = values[0], ans = 0;

        for(int i = 1; i < values.size(); i++){
            ans = max(ans, f + values[i] + f_ind - i);

            // cout << f << " " << f_ind << endl;

            if(f - (i - f_ind) <= values[i]){
                f_ind = i;
                f = values[i];
            }
        }

        return ans;
    }
};