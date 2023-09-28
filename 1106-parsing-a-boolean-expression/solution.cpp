class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        char op;

        for(int i = 0; i < expression.size(); i++){
            if(expression[i] != ',' && expression[i] != '(' && expression[i] != ')') st.push(expression[i]);
            
            else if(expression[i] == ')'){
                vector<char> ops;
                while (st.top() != '&' && st.top() != '|' && st.top() != '!'){
                    ops.push_back(st.top());
                    st.pop();
                }
                op = st.top();
                st.pop();

                if (op == '&') st.push((find(ops.begin(), ops.end(), 'f') != ops.end()) ? 'f' : 't');
                else if (op == '|') st.push((find(ops.begin(), ops.end(), 't') != ops.end()) ? 't' : 'f');
                else st.push((ops[0] == 't') ? 'f' : 't');
            }
        }       
        return st.top() == 't';
    }
};