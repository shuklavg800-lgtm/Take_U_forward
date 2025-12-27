#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Length of linked list
int length_LL(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Convert array to linked list
Node* convertArraytoLL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Delete at beginning
Node* deleteAtBegin(Node* head) {
    if (!head) return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete at end
Node* deleteAtEnd(Node* head) {
    if (!head) return nullptr;
    if (!head->next) {
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next->next) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return head;
}

// Delete at given position (1-based)
Node* deleteAtPos(Node* head, int pos) {
    if (!head || pos <= 0) return head;

    if (pos == 1) {
        return deleteAtBegin(head);
    }

    int len = length_LL(head);
    if (pos > len) {
        cout << "Invalid position\n";
        return head;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return head;
}

Node* deleteTheVal(Node* head, int val) {
    if (!head) return head;
    Node* curr = head;
    Node* prev = nullptr;
    while(curr->data!=val && curr->next !=nullptr){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    delete curr;
    return head;
}

// Print linked list
void printLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter value at position " << i + 1 << ": ";
        cin >> arr[i];
    }

    Node* head = convertArraytoLL(arr);

    // int pos;
    // cout << "Enter position to delete: ";
    // cin >> pos;

    int val;
    cout << "Enter the val to delete: ";
    cin >> val;

    cout << "Linked list before deletion:\n";
    printLL(head);

    // head = deleteAtPos(head, pos);

    head= deleteTheVal(head,val);

    cout << "Linked list after deletion:\n";
    printLL(head);

    return 0;
}
