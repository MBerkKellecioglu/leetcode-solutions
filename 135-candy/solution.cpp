class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size(), ans = 0, prev = -1;

        // not the most optimised version of my idea but im lazy so here you go 

        vector<int> lds(n, 0); // longest decreasing sequence(continuous)

        lds[n - 1] = 1;

        for(int i = 0; i < n - 1; i++){
            if(ratings[i] > ratings[i + 1]){
                int l = i, r = i;

                while(r < n - 1 && ratings[r] > ratings[r + 1]){
                    r++;
                }

                lds[l] = (r - l) + 1;
            }
            else lds[i] = 1;
        }


        for(int i = 0; i < n; i++){
            int maxi = 1;

            if(i - 1 > -1){
                if(ratings[i] > ratings[i - 1]){
                    maxi = max(maxi, prev + 1);
                }
            }

            maxi = max(maxi, lds[i]);

            if(i +  1 < n){
                if(ratings[i] > ratings[i + 1]){
                    maxi = max(maxi, lds[i + 1] + 1);
                }
            }

            ans += maxi;
            prev = maxi;
        }

        return ans;
    }
};