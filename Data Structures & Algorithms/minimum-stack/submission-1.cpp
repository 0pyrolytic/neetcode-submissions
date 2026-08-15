class MinStack {
public:
    vector<int> currStack;
    vector<int> minStack;

    MinStack() {}

    void push(int val) {
        currStack.push_back(val);
        if (minStack.empty()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(min(val, minStack.back()));
        }
    }

    void pop() {
        currStack.pop_back();
        minStack.pop_back();
    }

    int top() {
        return currStack.back();
    }

    int getMin() {
        return minStack.back();
    }
};