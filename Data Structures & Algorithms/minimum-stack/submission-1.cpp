class MinStack {
   public:
    stack<int> norm;
    stack<int> min;
    MinStack() {}

    void push(int val) {
        if (min.empty()) {
            min.push(val);
        } else {
            if (val <= min.top()) {
                min.push(val);
            }
        }
        norm.push(val);
    }

    void pop() {
        if (norm.empty()) {
            return;
        } else {
            if (norm.top() == min.top()) {
                min.pop();
            }
            norm.pop();
        }
    }

    int top() {

        return norm.top();
    }


    int getMin() {
        return min.top();
    }
};
