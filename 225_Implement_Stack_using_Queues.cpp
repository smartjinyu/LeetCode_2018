class MyStack {
public:
    /** Initialize your data structure here. */
    int last;
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        q1 = queue<int>();
        q2 = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        last = x;
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty()){
            while(q2.size() > 1){
                q1.push(last = q2.front());
                q2.pop();
            }
            int temp  = q2.front();
            q2.pop();
            return temp;
        }else{
            while(q1.size() > 1){
                q2.push(last = q1.front());
                q1.pop();
            }
            int temp  = q1.front();
            q1.pop();
            return temp;
        }
        
    }
    
    /** Get the top element. */
    int top() {
        return last;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */