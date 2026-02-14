#include <bits/stdc++.h>
using namespace std;
class infixTOprefix {
    int precedence(char c){
        if(c == '^')
            return 3;
        if(c == '*' || c == '/')
            return 2;
        if(c == '+' || c == '-')
            return 1;
        return -1;
    }
public:
    string infixToPrefix(const string& s) {
        // reversing the string with bracket modification
        string str=s;
        reverse(str.begin(),str.end());
        string ans;
        stack<char> st;

        // reversal of the bracket
        for(int i=0;i<s.size();i++){
            char current_element=str[i];
            if(current_element=='('){
                str[i]=')';
            }
            else if(current_element==')'){
                str[i]='(';
            }
        }
        // infix to postfix using the controlled precedence due to reversal
        for(int i=0;i<s.size();i++){
            char current_element=str[i];
            if(isalnum(current_element)){
                ans+=current_element;
            }
            else if(current_element=='('){
                st.push(current_element);
            }
            // case of closing bracket
            else if(current_element==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            // the case when it is operator
            else{
                // the case of left associative  and right associative that is ^ operators
                while(!st.empty() && (precedence(st.top())> precedence(current_element)|| (precedence(st.top())== precedence(current_element) && current_element=='^'))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(current_element);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    infixTOprefix obj;
    string str;
    cout<< "Enter the expression to find the prefix of:" << endl;
    cin >> str;
    // obj.infixToPrefix(str);
    cout << "the prefix of the input expression is:" << endl << obj.infixToPrefix(str);
    return 0;
}