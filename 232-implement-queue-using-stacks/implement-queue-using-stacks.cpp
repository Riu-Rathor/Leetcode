class MyQueue {
   stack<int> input; 
   stack<int> output;
   int peekElement = -1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekElement = x;
        }
        input.push(x);
    }
    
    int pop() {        
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int element = output.top();
        output.pop();
        return element;
    }
    
    int peek() {
        if(output.empty()) {
            return peekElement;
        }
        return output.top();
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