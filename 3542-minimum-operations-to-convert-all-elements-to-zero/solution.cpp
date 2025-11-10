class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        stack<int> inc;

        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            if(inc.size() == 0 || inc.top() < nums[i]){
                inc.push(nums[i]);
            }
            else{
                while(inc.size() > 0 && inc.top() > nums[i]){
                    inc.pop();
                    ans++;
                }

                if(inc.size() == 0 || inc.top() != nums[i]) inc.push(nums[i]);
            }
        }

        while(inc.size() != 0){
            int num = inc.top();

            inc.pop();
            if(num != 0) ans++;
        }

        return ans;
    }
};