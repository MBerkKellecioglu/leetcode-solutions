using ll = long long;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        ll sum1 = 0, sum2 = 0;

        int zcount1 = 0, zcount2 = 0;

        for(int& n : nums1){
            if(!n) zcount1++;

            sum1 += n;
        }

        for(int& n : nums2){
            if(!n) zcount2++;

            sum2 += n;
        }

        //cout << sum1 << " " << sum2 << " " << zcount1;

        if(sum1 == sum2){
            if( (zcount1 == 0 && zcount2 > 0) || (zcount1 > 0 && zcount2 == 0)) return -1;

            return sum1 + max(zcount1, zcount2);
        }
        else{
            sum1 += zcount1;
            sum2 += zcount2;

            if( (sum1 > sum2 && !zcount2) || (sum2 > sum1 && !zcount1)) return -1;

            return max(sum1, sum2);
        }

        return 0;
    }
};