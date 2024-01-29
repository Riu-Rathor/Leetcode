class MyQueue {
   stack<int> input; 
   stack<int> output; 
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int element;
        if(!output.empty()) {
            element = output.top();
            output.pop();
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            element = output.top();
            output.pop();
        }
        return element;
    }
    
    int peek() {
        int element;
        if(!output.empty()) {
            element = output.top();
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            element = output.top();
        }
        return element;
    }
    
    bool empty() {
        return input.empty() && output.empty();
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