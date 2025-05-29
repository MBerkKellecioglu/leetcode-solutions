class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        vector<bool> arr(n + 1, false);

        int mul = m, num1 = 0, num2 = 0;

        while(mul <= n){
            arr[mul] = true;

            mul += m;
        }

        for(int i = 1; i <= n; i++){
            (arr[i]) ? num2 += i : num1 += i;
        }

        return num1 - num2;
    }
};