class MyQueue {
public:
    stack<int> my_stack;
    stack<int> my_stack2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!my_stack.empty()){
            my_stack2.push(my_stack.top());
            my_stack.pop();
        }
        my_stack.push(x);
        while(!my_stack2.empty()){
            my_stack.push(my_stack2.top());
            my_stack2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = my_stack.top();
        my_stack.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return my_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return my_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
