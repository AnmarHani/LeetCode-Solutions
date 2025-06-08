class MinStack {
public:
    vector<int> stk;
    vector<int> minStk;

    MinStack() {
    }
    
    void push(int val) {
        stk.push_back(val);
        
        if(!minStk.empty()) 
            minStk.push_back(min(val, minStk.back()));
        else
            minStk.push_back(val);
    }
    
    void pop() {
        stk.pop_back();
        minStk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
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
