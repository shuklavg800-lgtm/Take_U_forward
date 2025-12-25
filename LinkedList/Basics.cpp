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
    // Node* curr =head;
    // for (int i = 1; i < n; i++)
    // {
    //     int temp_val;
    //     cout << "Enter the value to be inserted: "<< endl;
    //     cin >> temp_val;
    //     Node* temp= new Node(temp_val);
    //     curr->next=temp;
    //     curr=temp;
    // }
    Node* ptr=head;
    while(ptr!=nullptr){
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    return 0;
}