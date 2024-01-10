#include<iostream>

using namespace std;
class Node{
        public:
            int data;
            Node*next;
            //constructor ***********
        Node(int val){
            this->data=val;
            this->next=NULL;
        }
};

void insertAtHead(Node* &head,int d){
            // new node creation
            Node* temp = new Node(d);
            temp->next = head;
            head=temp;
}
void insertAtEnd(Node* &tail,int d){
            // new node creation
            Node*temp=new Node(d);
            tail->next=temp;
            tail=tail->next;
}
void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<< temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node*node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
    insertAtHead(head,12);
    insertAtEnd(tail,15);
    insertAtEnd(tail,20);
    print(head);
}