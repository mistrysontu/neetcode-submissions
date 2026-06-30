class MinStack {
public:
    stack<pair<int, int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.size() == 0){
            stk.push({val, val});
        }
        else{
            stk.push({val, min(val, stk.top().second)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
