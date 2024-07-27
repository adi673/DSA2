class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q1.size();
        for(int i=0; i<size; i++){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        for(int i=0; i<size; i++){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int data=q1.front();
        q1.pop();
        return data;
    }
    
    int top() {
        int data=q1.front();
        return data;
    }
    
    bool empty() {
        if(!q1.size()){
            return true;
        }
        return false;
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