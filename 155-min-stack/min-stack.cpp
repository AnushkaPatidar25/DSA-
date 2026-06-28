class MinStack {
public:
  stack<int>s;
  stack<int>min;
    MinStack() {
    }
    
    void push(int value) {
      s.push(value);
      if(min.empty()||value<=min.top()) 
      min.push(value);   
    }
    
    void pop() {
    if(s.top()==min.top())
        min.pop();
   
        s.pop();
      
    }
    
    int top() {
     int ans=s.top();
     return ans;
    }
    
    int getMin() {
     return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */