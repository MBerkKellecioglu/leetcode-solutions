class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        vector<int> sol(temperatures.size(), 0);
        stack<pair<int,int> > st;
        pair<int, int> ind_value(temperatures.size() - 1, temperatures[temperatures.size() - 1]);

        st.push(ind_value);
        
        for(int i = temperatures.size() - 1; i > 0; i--){
            while(!st.empty()){
                ind_value.first = i - 1;
                ind_value.second = temperatures[i - 1];
                if(temperatures[i - 1] > st.top().second) st.pop();
                else if(temperatures[i - 1] == st.top().second){
                    if(sol[st.top().first] == 0) sol[i - 1] = 0;
                    else sol[i - 1] = sol[st.top().first] + abs(i - 1 - st.top().first);
                    st.push(ind_value);
                    break;
                } 
                else{
                    sol[i - 1] = abs(i - st.top().first - 1);
                    st.push(ind_value);
                    break;
                }
                if(st.empty()) st.push(ind_value);
            }
        }
        return sol;
    }
};