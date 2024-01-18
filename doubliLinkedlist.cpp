#include<iostream>

using namespace std;
class Node{
    public :
        int data;
        Node*next;
        Node*prev;
        Node(int val){
            this->data=val;
            this->prev=NULL;
            this->next=NULL;
        }
};
    void insertAtHead(Node* &head,int d){
        Node*temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    void insertAtTail(Node* &tail,int d){
        Node*temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=tail->next;
    }
     void print(Node* &head){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int length(Node* &head){
        int len=0;
        Node*temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }

int main(){
    Node*node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
    print(head);
    cout<<length(head)<<endl;
    insertAtHead(head,56);
    print(head);
    cout<<length(head)<<endl;
    insertAtTail(tail,12);
    print(head);
    cout<<length(head)<<endl;



}