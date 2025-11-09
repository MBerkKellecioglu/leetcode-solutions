class Solution {
public:
    int countOperations(int num1, int num2){ 
        
        if(num2 > num1) swap(num1, num2);

        int ans = 0;

        while(num1 != 0 && num2 != 0){

            int div = num1 / num2;

            ans += div;

            num1 -= div * num2;

            if(num2 > num1) swap(num1, num2);
        }

        return ans;
    }
};