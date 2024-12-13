class MyStack {
private:
    queue<int> queue1, queue2;
public:
    MyStack() { }

    void push(int x) {
        queue1.push(x); // Push to queue1 directly
    }

    int pop() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front()); // Transfer all but the last element
            queue1.pop();
        }
        int x = queue1.front(); // The last element is the stack top
        queue1.pop(); // Remove it
        swap(queue1, queue2); // Swap queues
        return x;
    }

    int top() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int x = queue1.front(); // Get the last element
        queue2.push(x);         // Push it to queue2 to maintain structure
        queue1.pop();
        swap(queue1, queue2); // Swap queues
        return x;
    }

    bool empty() {
        return queue1.empty();
    }
};
