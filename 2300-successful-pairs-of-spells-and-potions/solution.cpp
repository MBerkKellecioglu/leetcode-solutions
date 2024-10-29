class Solution {
    using ll = long long;
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());

        int p_size = potions.size();

        vector<int> ans;

        for(int i = 0; i < spells.size(); i++){
            int l = 0, r = p_size, ind = -1;

            ll s = spells[i];

            while(l < r){
                int mid = l + (r - l) / 2;

                if(s * ll(potions[mid]) >= success){
                    if(mid - 1 > -1 && s * potions[mid - 1] < success){
                        ind = mid;
                        break;
                    }
                    else r = mid - 1;
                }
                else{
                    if(mid + 1 < p_size && s * ll(potions[mid + 1]) >= success){
                        ind = mid + 1;
                        break;
                    }
                    l = mid + 1;
                }
            }

            if(l == 0 && r <= 0) ans.push_back(p_size);
            else if(ind == -1) ans.push_back(0);
            else ans.push_back(p_size - ind);
        }

        return ans;
    }
};