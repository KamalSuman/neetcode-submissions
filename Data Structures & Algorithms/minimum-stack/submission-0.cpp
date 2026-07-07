class MinStack {
public:
    MinStack() {
        
    }
    stack<int> st1;
        stack<int> st2;
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || st2.top() >= val){
            st2.push(val);
        } 
    }
    
    void pop() {
        int x = st1.top();
        if(x == st2.top()) st2.pop();
        st1.pop(); 
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
