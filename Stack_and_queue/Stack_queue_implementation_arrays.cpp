#include <iostream>
using namespace std;


class st_implementation {
    int arr[10];
    int top_index = -1;

public:

    void push(int x) {
        if (top_index < 9) {
            arr[++top_index] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop() {
        if (top_index >= 0) {
            return arr[top_index--];
        } else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int top() {
        if (top_index >= 0)
            return arr[top_index];
        else {
            cout << "Stack Empty\n";
            return -1;
        }
    }

    int size() {
        return top_index + 1;
    }
};


class queue_implementation {
    int size = 10;
    int arr[10];
    int start = -1;
    int end = -1;

public:

    void push(int x) {

        if ((end + 1) % size == start) {
            cout << "Queue Overflow\n";
            return;
        }

        if (start == -1) {
            start = end = 0;
        } else {
            end = (end + 1) % size;
        }

        arr[end] = x;
    }

    int pop() {

        if (start == -1) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int element = arr[start];

        if (start == end) {
            start = end = -1;
        } else {
            start = (start + 1) % size;
        }

        return element;
    }

    int top() {
        if (start == -1) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[start];
    }
};


int main() {

    st_implementation st;
    queue_implementation q;

    st.push(10);

    st.push(20);

    cout << "Stack top: " << st.top() << endl;

    q.push(100);
    q.push(200);

    cout << "Queue front: " << q.top() << endl;
    cout << "popped element"<<q.pop();
    cout << "popped element"<<q.pop();
    cout << "popped element"<<q.pop();

    return 0;
}
