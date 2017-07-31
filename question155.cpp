class MinStack {
public:
    vector<int> min;
    vector<int> stack;
    /** initialize your data structure here. */
    MinStack() {
        min.clear();
        stack.clear();
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min.size()==0)
        {
            min.push_back(x);
            
        }
        else
        {
            if(x<=min.back())
                min.push_back(x);
        }
        
    }
    
    void pop() {
        if(stack.back()==min.back())
        {
            stack.pop_back();
            min.pop_back();
        }
        else if(stack.back()>min.back())
        {
            stack.pop_back();
        }
        
        
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
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