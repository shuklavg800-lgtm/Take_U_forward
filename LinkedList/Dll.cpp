#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

// Print linked list forward
void printLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Print linked list backward
void printReverse(Node* head) {
    if (!head) return;
    while (head->next) head = head->next; // go to last node
    while (head) {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

// Create DLL iteratively
Node* create_DLL(int n) {
    if (n < 1) return nullptr;

    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 2; i <= n; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        Node* curr = new Node(val);
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    return head;
}

// To reverse a Doubly Linked list
Node* reverse_dll(Node* head) {
    if (!head) return nullptr;

    Node* curr = head;
    Node* temp = nullptr;

    while (curr) {
        // swap prev and next
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // move to next node (which is prev after swap)
        curr = curr->prev;
    }

    // new head
    if (temp)
        head = temp->prev;

    return head;
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    while (n < 1) {
        cout << "Enter a valid value: ";
        cin >> n;
    }

    Node* head = create_DLL(n);

    cout << "Linked list forward: ";
    printLL(head);

    cout << "Linked list backward: ";
    printReverse(head);

    return 0;
}
