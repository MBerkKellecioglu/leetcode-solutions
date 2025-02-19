class Solution {
public:
    string smallestNumber(string pattern){
        
        string ans = "";

        bool nums[10];

        bool flag = false;

        for(int i = 0; i < 10; i++){
            nums[i] = 1;
        }

        dfs(ans, pattern, nums, flag);

        return ans;
    }

    void dfs(string& ans, string& patterns, bool (&nums)[10], bool& flag){

        if(ans.size() == patterns.size() + 1){
            flag = true;
            return;
        }

        for(int i = 1; i < 10; i++){
            if(nums[i]){
                if(!ans.empty()){
                    char pattern = patterns[ans.size() - 1];
                    int last_num = ans.back() - '0';

                    if( (pattern == 'D' && last_num > i) || (pattern == 'I' && last_num < i) ){
                        ans += to_string(i);

                        nums[i] = false;

                        dfs(ans, patterns, nums, flag);

                        if(!flag){

                            nums[i] = true;

                            ans.pop_back();
                        }                   
                    }
                }
                else{
                    ans += to_string(i);

                    nums[i] = false;

                    dfs(ans, patterns, nums, flag);

                    if(!flag){
                        nums[i] = true;

                        ans.pop_back();
                    }
                }
            }
        }
    }
};