class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> nums;

        string sol = "";

        int dec = 1;

        for(int i = 1; i < n + 1; i++) nums.push_back(i);

        rec(nums, sol, n, k, dec);

        return sol;        
    }

    void rec(vector<int>& nums, string& sol, int& n, int& k, int& dec){

        if(nums.size() == 0) return;
        
        int step = compute_Perm(n - dec);
        int count = 0;

        while(k > step){
            k -= step;
            count++;
        }

        sol += to_string(nums[count]);

        nums.erase(nums.begin() + count);

        dec++;

        rec(nums, sol, n, k, dec);
    }

    int compute_Perm(int n){

        int sol = 1;

        while(n > 0){
            sol *= n;
            n--;
        }

        return sol;
    }
};