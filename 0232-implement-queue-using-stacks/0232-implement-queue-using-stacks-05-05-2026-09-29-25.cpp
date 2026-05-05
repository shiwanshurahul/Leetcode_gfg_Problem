class MyQueue {
public:
        //2 ds lene ka mtlab hi hai ek se push and ek s pop,pek
        //q: ins<-r[3,2,1]f->del
        //queue using stacks: push->s1 me , pop->s2 se
        // push-> s1 me push x
        // pop-> return -1 if both s1 and s2 are empty
        // if st2 is empty -> s1 se sb s2 me daal do
        //     return st2.top() 
        stack<int> st1,st2;
    MyQueue() {
    
    }
    
    void push(int x) {
        st1.push(x);   //1,2,3
    }
    
    int pop() {
        if(st1.empty() && st2.empty())
            return -1;
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top()); //3,2,1
                st1.pop();
            }
        }
        return st2.top();  //1
    }
    
    bool empty() {
        if(st1.empty() && st2.empty())
        return true;
        return false;
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