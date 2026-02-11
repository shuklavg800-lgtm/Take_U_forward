#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=nullptr;
    }
};

class st_implementaion{
    public:
    int curr_size=0;
    Node* top=nullptr;

    void push(int x){
        Node* temp=new Node(x);
        temp->next=top;
        curr_size++;
        top=temp;
        cout<< "Element Inserted";
        return;
    }
    int pop(){
        Node* temp=top;
        top=top->next;
        int element=temp->val;
        curr_size--;
        delete(temp);
        return element;
    }
    int top(){
        return top->val;
    }
    int size(){
        return curr_size;
    }
};

class queue_implementation{
    public:
    int curr_size=0;
    Node* start=nullptr;
    Node* end=nullptr;

    // insertion at the end
    void insert(int x){
        Node* temp=new Node(x);
        if(start==nullptr){
            start=end=temp;
        }
        else{
            end->next=start;
            end=temp;
        }
        curr_size++;
        cout<< "Element Inserted" <<endl;
        return;
    }

    // deletion from the head side ie start side
    int pop(){
        if(start==nullptr){
            cout<< "queue underflow"<<endl;
            return -1;
        }
        Node* temp=start;
        int element=temp->val;
        curr_size--;
        start=start->next;

        // the condition when the queue becomes empty, if we don't do this , the end will already be
        // pointing to the memory which has already been freed
        // and if we insert using end->next =temp, the function will try to access a memory which has alrady been freed which will 
        // result in an error
        // this becomes a case of dangling pointer
        if(start==nullptr){
            end=nullptr;
        }

        delete(temp);
        return element;
    }
    int top(){
        return start->val;
    }
    int size(){
        return curr_size;
    }
};