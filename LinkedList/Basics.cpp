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

int length_LL(Node* head){
    Node* temp=head;
    int length=0;
    while(temp){
        length++;
        temp=temp->next;
    }
    return length;
}

Node* last_element(Node* head){
    Node* curr=head;
    while(curr->next !=nullptr){
        curr=curr->next;
    }
    return curr;
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

int main(){
    int n=0;
    cout << "Enter the no of nodes you want to have in the linked list: "<< endl;
    cin >> n;
    vector<int> temporary(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value to be inserted: "<< endl;
        cin >> temporary[i];
    }

    Node* head= convertArraytoLL(temporary);

    // cout << "Length of linked list is: " << length_LL(head) << endl;

    // cout << "The last element of linked list is: " << last_element(head)->data << endl;

    int temp;
    cout<< "Enter the element to search in the LL:";
    cin>>temp;
    if(searchInLL(head,temp)){
        cout<< "Yes element is present";
    }
    else{
        cout<<"Element not present";
    }
    
    // Node* ptr=head;
    // while(ptr!=nullptr){
    //     cout << ptr->data << " ";
    //     ptr=ptr->next;
    // }
    return 0;
}