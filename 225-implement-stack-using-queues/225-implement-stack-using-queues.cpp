class MyStack {
public:
    queue<int> a, b;
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(a.size()!=1){
            b.push(a.front());
            a.pop();
        }
        int an = a.front();
        a.pop();
        while(!b.empty()){
            a.push(b.front());
            b.pop();
        }
        return an;
        
    }
    
    int top() {
        return a.back();
        
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */