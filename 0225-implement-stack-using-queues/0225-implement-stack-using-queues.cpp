class MyStack {
private:
    queue<int>queue1, queue2;
public:
    MyStack() {
    }
    
    void push(int x) {
        queue2.push(x);
       while(!queue1.empty()){
        queue2.push(queue1.front());
        queue1.pop();
       }
       swap(queue1, queue2);
    }
    
    int pop() {
        int x = queue1.front();
        queue1.pop();
        return x;
    }
    int top() {
        return queue1.front();
    }
    
    bool empty() {
       return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */