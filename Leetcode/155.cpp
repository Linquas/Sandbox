class MinStack {
private:
    stack<int> store;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        if (min.empty() || val <= min.top()) {
            min.push(val);
        }
        store.push(val);
    }
    
    void pop() {
        if (min.top() == store.top()) {
            min.pop();
        }
        store.pop();
    }
    
    int top() {
        return store.top();
    }
    
    int getMin() {
        return min.top();
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