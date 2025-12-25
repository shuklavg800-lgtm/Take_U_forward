#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=nullptr;
    }
};

int length_LL(Node* head){
    Node* temp=head;
    int length=0;
    while(temp){
        length++;
        temp=temp->next;
    }
    return length;
}


Node* convertArraytoLL(vector<int> & arr){
    Node* head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        curr->next=temp;
        curr=temp;
    }
    return head;
}

bool searchInLL(Node* head, int key){
    Node* temp=head;
    while (temp)
    {
        if(temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

// insertion

// to insert at the begining
Node* insertAtBegin(Node* head){
    int val;
    cout<< "Enter the val to be inserted:" << endl;
    cin >> val;
    Node* temp=new Node(val);
    temp->next=head;
    head=temp;
}

Node* insertAtEnd(Node* head){
    int val;
    cout<< "Enter the val to be inserted:" << endl;
    cin >> val;
    Node* curr=head;
    while (curr->next !=nullptr)
    {
        curr=curr->next;
    }
    
    Node* temp=new Node(val);
    curr->next=temp;
}
void printLL(Node* head){
    Node* curr =head;
    while(curr){
        cout<< curr->data << " ";
        curr=curr->next;
    }
}

Node* insertAnyPos(Node* head,int pos){
    int val;
    if(pos==1){
        insertAtBegin(head);
    }
    else if(pos>=length_LL(head)){
        insertAtEnd(head);
    }
    else{
        cout<< "Enter the val to be inserted:" << endl;
        cin >> val;
        Node* curr=head;
        Node* temp=new Node(val);
        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
    return head;
}


int main(){
    int n=0;
    cout << "Enter the no of nodes you want to have in the linked list: "<< endl;
    cin >> n;
    vector<int> temporary(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value at position: "<< i+1 << endl;
        cin >> temporary[i];
    }
    Node* head= convertArraytoLL(temporary);
    int pos;
    cout<< "Enter the position to be inserted at:" << endl;
    cin >> pos;
    cout << "Linked list before:" << endl;
    printLL(head);
    insertAnyPos(head,pos);
    cout << "Linked list After:" << endl;
    printLL(head);
    return 0;
}