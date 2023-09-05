class MinStack {
public:
    std::vector<int> st;
    MinStack(){
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop(){
        st.pop_back();
    }
    
    int top(){
        return st[st.size() - 1];
    }
    
    int getMin(){
        int minimum = st[0];
        for(int i = 0; i < st.size(); i++){
            if(st[i] < minimum) minimum = st[i];
        }
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */