class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;

        for(int num : nums){
            int curr = divNum(num);

            if(curr != -1) ans += curr + num + 1;
        }

        return ans;
    }

    int divNum(int num){
        
        int div = 0, div_sum = 0;

        for(int i = 2; i <= sqrt(num); i++){
            if(div > 2) return -1;

            if(num % i == 0){
                if(num / i == i){
                    div_sum += i;
                    div++;
                }
                else{
                    div += 2;
                    div_sum += i + (num / i);
                }
            }
        }

        if(div != 2) return -1;

        return div_sum;
    }   
};