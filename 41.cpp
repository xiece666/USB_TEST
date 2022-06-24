class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s,mi;
    MinStack() {
        
        mi.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        mi.push(min(mi.top(),x));
    }
    
    void pop() {
        s.pop();
        mi.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mi.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */