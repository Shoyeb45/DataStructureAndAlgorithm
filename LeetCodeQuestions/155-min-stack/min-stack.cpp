class MinStack {
public:
    stack<int> st, mn_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (mn_stack.empty()) {
            mn_stack.push(val);
            return;
        }

        if (mn_stack.top() >= val) {
            mn_stack.push(val);
        }
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if (val == mn_stack.top()) {
            mn_stack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn_stack.top();
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