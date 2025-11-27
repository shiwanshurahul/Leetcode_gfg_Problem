class MinStack {
public:
        stack<int> st;
        stack<int> sst;
    MinStack() {
    }
    
    void push(int val) {
            st.push(val);
            if(sst.size()==0)
            sst.push(val);
       else if(val<=sst.top())
            sst.push(val);
        
    }
    
    void pop() {
        if(sst.empty())
        return; 
        if(st.top()==sst.top()){ //
        st.pop();
        sst.pop();
        }
    else
    st.pop();
    }
    
    int top() {
        if(st.empty())
        return 0;
        return st.top();
    }
    
    int getMin() {
        if(sst.empty())
        return 0;
        return sst.top();
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