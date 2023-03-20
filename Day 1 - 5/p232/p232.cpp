#include <stack>
#include <assert.h>
using namespace std;


class MyQueue {
private:
    stack<int> a;
    stack<int> b;
    void transfer(stack<int>& x, stack<int>& y){
        assert(y.empty());
        while (!x.empty()){
            y.push(x.top());
            x.pop();
        }
    }  
public:
    MyQueue() {
        a = {};
        b = {};
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if (b.empty()){
            transfer(a, b);
        }
        int val = b.top();
        b.pop();
        return val;
    }
    
    int peek() {
        if (b.empty()){
            transfer(a, b);
        }
        int val = b.top();
        return val;
    }
    
    bool empty() {
        return a.empty() and b.empty();
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