class MinStack {
private:
    stack<int> arr;    
    stack<int> small;

public:
    MinStack() {

    }
    
    void push(int val) {
        arr.push(val);

        if (small.empty() || val <= small.top()) small.push(val);
        
    }
    
    void pop() {
        if (!arr.empty()) {
            if (arr.top() == small.top()) small.pop();
            arr.pop();
        }
    }
    
    int top() {
        return arr.top();
    }
    
    int getMin() {
        return small.top();            
    }

};
