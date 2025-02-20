class Solution {
public:
    string getHappyString(int n, int k) {
        
        vector<char> abc = {'a', 'b', 'c'};

        string ans = "";
        string tmp = "";

        bool flag = false;

        dfs(ans, tmp, abc, n, k, flag);

        return ans;
    }

    void dfs(string& ans, string& tmp, vector<char>& abc, int& n, int& count, bool& flag){

        if(flag) return;

        if(tmp.size() == n){
            count--;

            if(count == 0){
                ans = tmp;
                flag = true;
            }
            
            return;
        }

        for(int i = 0; i < 3; i++){
            if(tmp.empty() || tmp.back() != abc[i]){
                tmp += abc[i];

                dfs(ans, tmp, abc, n, count, flag);

                tmp.pop_back();
            } 
        }
    }
};