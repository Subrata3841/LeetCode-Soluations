class MyQueue {
private:
stack<int>stack1, stack2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if(stack2.empty()){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
            }
        }
        if(stack2.empty()){
            return -1;
        }
        int x = stack2.top();
        stack2.pop();
        return x;
    }
    
    int peek() {
        if(stack2.empty()){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
            }
        }
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty()&&stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */