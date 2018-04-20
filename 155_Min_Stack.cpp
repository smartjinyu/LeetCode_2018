class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> asist;
    MinStack() {
        data = stack<int>();
        asist = stack<int>();
    }
    
    void push(int x) {
        data.push(x);
        if(asist.empty() || x < asist.top()){
            asist.push(x);
        }else{
            asist.push(asist.top());
        }
    }
    
    void pop() {
        data.pop();
        asist.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return asist.top();
    }
};
