class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>input,output;
    MyQueue(){
        input = output;
    }
    
    /** Push element x to the back of queue. */
    void push(int x){
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop(){
        int ele;
        if(!output.empty()){
            ele = output.top();
            output.pop();
        }else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            ele = output.top();
            output.pop();
        }
       return ele; 
    }
    
    /** Get the front element. */
    int peek(){
        int ele;
        if(!output.empty()){
            ele = output.top();
        }else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            ele = output.top();
        }
       return ele; 
    }
    
    /** Returns whether the queue is empty. */
    bool empty(){
        if(input.size() == 0 && output.size() == 0){
            return true;
        }
        return false;
    }
};