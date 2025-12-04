using ll = long long;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries){

        ll sum = 0;

        for(int& battery : batteries){
            sum += battery;
        }

        ll l = 0, r = sum; // left right

        while(l < r){
            ll target = r - (r - l) / 2, backup = 0;

            for(int battery : batteries) backup += min(target, ll(battery));

            if(backup >= n * target) l = target;
            else r = target - 1;
        }

        return l;
    }
};