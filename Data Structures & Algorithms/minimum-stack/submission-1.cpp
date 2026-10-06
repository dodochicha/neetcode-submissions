class MinStack {
    stack<int> dataStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        dataStack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        }
        else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
