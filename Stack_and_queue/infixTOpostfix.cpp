#include <iostream>
using namespace std;
#include <stack>

class MinStack {
public:
    stack<int> st;
    stack<int> mini;

    MinStack() {}

    void push(int val) {
        if(mini.empty() || val <= mini.top()){
            mini.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(!mini.empty() && st.top() == mini.top()){
            mini.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

int main() {
    MinStack obj;

    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(0);

    cout << "Top: " << obj.top() << endl;
    obj.pop();
    
    cout << "Top: " << obj.top() << endl;
    cout << "Min: " << obj.getMin() << endl;
    obj.push(40);
    cout << "Top: " << obj.top() << endl;

    return 0;
}
