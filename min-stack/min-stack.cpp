class MinStack {
public:
    /** initialize your data structure here. */
    int stack[10000];
    int mini[10000];
    int front;
    int minimum;
    MinStack() {
        front = -1;
        minimum = -1;
    }
    
    void push(int val) {
        if(front >= 10000){
            return ;
        }else{
            stack[++front] = val;
        }
        
        if(minimum == -1){
            mini[++minimum] = val;
        }else{
            mini[++minimum] = min(mini[minimum],val);
        }
    }
    
    void pop() {
        if(front == - 1){
            return ;
        }
        front -= 1;
        minimum -= 1;
    }
    
    int top(){
        return stack[front];
    }
    
    int getMin() {
        return mini[minimum];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */