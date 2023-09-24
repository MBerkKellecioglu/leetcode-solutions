class Solution {
public:
    string countOfAtoms(string formula){
        std::stack<std::pair<int, int>> st;
        std::pair<int, int> pr;
        int multpl = 1;
        string tmp_s = "";
        std::map<string, int> main_mp;

        for(int i = formula.size() - 1; i > -1; i--){
            if(isdigit(formula[i])){
                tmp_s += formula[i];
                while(isdigit(formula[i - 1])){
                    i--;
                    tmp_s.insert(0, string(1,formula[i]));
                }
                pr.first = stoi(tmp_s);
                if(isalpha(formula[i - 1])) pr.second = 1;
                else pr.second = 0;
                st.push(pr);
                multpl *= pr.first;
                tmp_s = "";
            }
            else if(isalpha(formula[i])){
                tmp_s += formula[i];
                if(islower(formula[i])){
                    tmp_s.insert(0, string(1,formula[i - 1]));
                    i--;
                }
                main_mp[tmp_s] += multpl;
                if(!st.empty() && st.top().second == 1){
                    multpl /= st.top().first;
                    st.pop();
                }
                tmp_s = "";
            }
            else if(formula[i] == '('){
                if(!st.empty()){
                    multpl /= st.top().first;
                    st.pop();
                }
            }
        }

        for(auto elements : main_mp){
            tmp_s += elements.first;
            if(elements.second == 1) continue;
            tmp_s += to_string(elements.second);
        }
        return tmp_s;
    }
};