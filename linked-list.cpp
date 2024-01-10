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
void insertAtPosition(Node* &head,int pos,int d){
            Node*temp=head;
            int count=1;
            while(count<pos-1){
                temp=temp->next;
                count++;
            }
            Node*node2=new Node(d);
            node2->next=temp->next;
            temp->next=node2;
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
    print(head);
    cout<<endl;
    insertAtEnd(tail,15);
    print(head);
     cout<<endl;
    insertAtEnd(tail,20);
    print(head);
     cout<<endl;
    insertAtPosition(head,3,60);
    print(head);
}