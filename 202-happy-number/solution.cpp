class Solution {
public:
    bool isHappy(int n){
        
        int sum = n;

        while(sum != 1 && sum != 4){
            sum = calculate(sum);
        }

        if(sum == 1) return true;
        
        return false;
    }

    int calculate(int n){

        int sum = 0;

        while(n > 0){
            int tmp = n % 10;
            n /= 10;
            sum += (tmp*tmp);
        }

        return sum;
    }
};