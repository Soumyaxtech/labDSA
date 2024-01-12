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
void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
            if(pos==1){
                insertAtHead(head,d);
                return;
            }
            Node*temp=head;
            int count=1;
            while(count<pos-1){
                temp=temp->next;
                count++;
            }
            if(temp->next==NULL){
                insertAtEnd(tail,d);
                return;
            }
            Node*node2=new Node(d);
            node2->next=temp->next;
            temp->next=node2;
}
void deleteHead(Node* &head){
    Node*prev=NULL;
    Node*curr=head;
    prev=head;
    head=curr->next;
    delete prev;
}
void deleteAny(int pos,Node* &head){
    if(pos==1){
        deleteHead(head);
        return;
    }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
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
    insertAtPosition(tail,head,5,60);
    print(head);
    cout<<endl;
    deleteHead(head);
    print(head);
    cout<<endl;
    deleteAny(2,head);
    print(head);
}