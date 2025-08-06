class MinStack {
public:
    // stack<int> st;
    // stack<int> mini;
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        } else{
            stk.push({val, min(val, stk.top().second)});
        }
        // st.push(val);
        // if(mini.empty()){
        //     mini.push(st.top());
        // } else{
        //     mini.push(min(st.top(), mini.top()));
        // }
    }
    
    void pop() {
        stk.pop();
        // mini.pop();
        // st.pop();
    }
    
    int top() {
        return stk.top().first;
        // return st.top();
    }
    
    int getMin() {
        return stk.top().second;
        // return mini.top();
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