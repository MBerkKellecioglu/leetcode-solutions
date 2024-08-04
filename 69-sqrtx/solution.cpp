class Solution {
public:
    int mySqrt(int x) {

        if(x == 0) return 0;
        
        int l = 1, r = x;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(x / mid < mid) r = mid - 1;
            else if(x / mid > mid) l = mid + 1;
            else return mid;
        }

        return r;
    }
};