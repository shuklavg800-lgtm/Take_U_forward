#include <iostream>
using namespace std;
#include <stack>

class infixTOpostfix {
public:

    int precedence(char c){
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string ans;

        for(int i = 0; i < s.size(); i++) {

            // If operand, add to result
            if((s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9')) {
                
                ans += s[i];
            }

            // If '(', push to stack
            else if(s[i] == '(') {
                st.push(s[i]);
            }

            // If ')', pop until '('
            else if(s[i] == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }

            // Operator case
            else {
                // popping elements
                while(!st.empty() &&
                     ((precedence(s[i]) < precedence(st.top())) ||
                     (precedence(s[i]) == precedence(st.top()) && s[i] != '^'))) {
                    
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        // Pop remaining operators
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};


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
