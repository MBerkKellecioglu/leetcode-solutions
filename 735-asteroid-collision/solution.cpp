class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> cache;
        vector<int> ans;

        for(int& n : asteroids){
            if(!cache.empty()){
                if(cache.top() > 0 && n < 0){
                    bool skip = 0;
                    while(!cache.empty() && cache.top() > 0 && n < 0){
                        if(abs(cache.top()) > abs(n)){
                            skip = 1;
                            break;
                        }
                        else if(abs(cache.top()) == abs(n)){
                            cache.pop();
                            skip = 1;
                            break;
                        }
                        else{
                            cache.pop();
                        }
                    }
                    if(!skip) cache.push(n);
                }
                else cache.push(n); 
            }
            else cache.push(n);
        }

        while(!cache.empty()){
            ans.push_back(cache.top());
            cache.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};