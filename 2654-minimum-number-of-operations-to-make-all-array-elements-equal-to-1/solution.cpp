class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size(), one_count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1) one_count++;
        }

        if(one_count > 0) return n - one_count;

        int ans = INT_MAX;

        for(int i = 0; i < n - 1; i++){
            int total_gcd = gcd(nums[i], nums[i + 1]);

            if(total_gcd == 1) return n;

            for(int j = i + 2; j < n; j++){
                total_gcd = gcd(total_gcd, nums[j]);

                if(total_gcd == 1){
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }

    int gcd(int a, int b){

        while(b){
            a %= b;
            swap(a, b);
        }

        return a;
    }
};