#include <queue>
using namespace std;


class MyStack {
private:
    queue<int> a, b;
    void transfer(queue<int>& x, queue<int>& y) {
        while (!x.empty()) {
            y.push(x.front());
            x.pop();
        }
    }


public:
    MyStack() {
        a = {};
        b = {};
    }
    
    void push(int x) {
        transfer(a, b);
        a.push(x);
        transfer(b, a);
    }
    
    int pop() {
        int val = a.front();
        a.pop();
        return val;
    }
    
    int top() {
        return a.front();
    }
    
    bool empty() {
        return a.empty() and b.empty();
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