#include<iostream>

using namespace std;
class Node{
    public :
        int data;
        Node*next;
        Node*prev;
    Node(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class doubly{
    private :
        Node*head;
        Node*tail;
    public :
    doubly(){
        this->head=NULL;
        this->tail=NULL;
    }
    void insertAtHead(int val){
        Node*temp=new Node(val);
        if(head==NULL){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        cout<<val<<" inserted into linkedlist \n";
    }
    void insertAtEnd(int val){
        Node*temp=new Node(val);
        if(tail==NULL){
            tail=temp;
        }
        else{
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        cout<<val<<" inserted into linkedlist\n";
    }
    void insertAtPosition(int pos,int val){
        if(pos==1){
            insertAtHead(val);
            return;
        }
        Node*temp=head;
        int count=1;
        while(count<pos-1  &&  temp!=NULL){
            cout<<temp->data<<endl;
            cout<<count<<endl;
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            insertAtEnd(val);
            return;
        }
        Node*node1=new Node(val);
        node1->next=temp->next;
        temp->next->prev=node1;
        node1->prev=temp;
        temp->next=node1;
    }
    void display(){
        if(head==NULL){
            cout<<"the linked-list is empty can't display anything ";
            return;
        }
        cout<<"the linked-list elements are ";
            Node*temp=head;
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
          cout<<endl;
    }
};

int main(){
    int choice,val,pos;
    doubly l2;
    do{
        cout<<"DOUBLY-LINKEDLIST OPERATIONS\n1. insert at begining\n2. insert at end\n3. insert any position\n7. display\n0. exit\n";
        cout<<"ENTER THE OPERATION YOU WANT TO PERFORM ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the element to insert ";
                cin>>val;
                l2.insertAtHead(val);
                break;
            case 2:
                cout<<"enter the element to insert at end ";
                cin>>val;
                l2.insertAtEnd(val);
                break;
            case 3:
                cout<<"enter the position you want to insert element ";
                cin>>pos;
                cout<<"enter the element ";
                cin>>val;
                l2.insertAtPosition(pos,val);
                break;
            case 7:
                l2.display();
                break;
        }
    }while(choice);
}