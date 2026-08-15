class MinStack {
public:
    vector<int>currStack;
    MinStack() {
    }
    
    void push(int val) {
        currStack.push_back(val);
    }
    
    void pop() {
        currStack.pop_back();
    }
    
    int top() {
        return currStack.back();
    }
    
    int getMin() {
        int min = currStack[0];
        for(int n : currStack){
            if(n < min){
                min = n;
            }
        }
        return min;
    }
};
