class MinStack {
public:
    stack<int>st1,st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || st2.top()>=val)
            st2.push(val);
    }
    
    void pop() {
        if(st1.empty())
            return;
        if(st1.top()==st2.top())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        if(st1.empty())
            return -1;
        return st1.top();
    }
    
    int getMin() {
        if(st1.empty())
            return -1;
        return st2.top();
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