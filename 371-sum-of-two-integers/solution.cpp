class Solution {
public:
    int getSum(int a, int b) {

        while(b != 0){
            int tmp = (b & a) << 1;
            a = a ^ b;
            b = tmp;
        }  

        return a;
    }
};