class Solution {
public:
    double myPow(double x, int n){

        double sol = calculate(x, abs(n));

        if(n < 0) return 1.000 / sol;
        
        return sol;
    }

    double calculate(double x, int n){

        if(n == 0) return 1;

        double tmp = calculate(x, n / 2);

        if(n % 2 == 0) return tmp * tmp;
        else return x * tmp * tmp;

        return 1;
    }
};