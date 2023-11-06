class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if(minStack.empty() || minStack.top() >= val)
            minStack.push(val);
    }
    
    void pop() {
        if(stack.empty())
            return;

        if(stack.top() == minStack.top())
            minStack.pop();
        stack.pop();
    }
    
    int top() {
        if(stack.empty())
            return 0;

        return stack.top();
    }
    
    int getMin() {
        if(minStack.empty())
            return 0;
        return minStack.top();
    }
private:
    std::stack<int> minStack;
    std::stack<int> stack;
};