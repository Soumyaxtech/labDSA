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
class circularDoubly{
    private :
        Node*head;
        Node*tail;
    public :
    circularDoubly(){
        this->head=NULL;
        this->tail=NULL;
    }
    void insertHead(int item){
        Node*temp=new Node(item);
        if(head==NULL){
            head=tail=temp;
            temp->next=head;
            temp->prev=tail;
            return;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
            temp->prev=tail;
            tail->next=temp;
        }
    }
    void insertEnd(int item){
        Node*temp=new Node(item);
        if(tail==NULL){
            tail=temp;
            temp->next=head;
            temp->prev=tail;
            return;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            temp->next=head;
            head->prev=temp;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"the list is empty "<<endl;
            return;
        }
        Node*temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
};

int main(){
    int choice,item,pos;
    circularDoubly d1;
    do{
        cout<<"CIRCULAR-DOUBLY-LINKEDLIST OPERATIONS\n1. insertAtHead\n2. insertAtEnd\n7. display\n0. exit\n";
        cout<<"ENTER THE OPERATION YOU WANT TO PERFORM ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter element to insert ";
                cin>>item;
                d1.insertHead(item);
                d1.display();
                break;
            case 2:
                cout<<"enter element to insert ";
                cin>>item;
                d1.insertEnd(item);
                d1.display();
                break;
            case 7:
                d1.display();
                break;
            case 0:
                cout<<"exit from this code ";
                break;
            default :
                cout<<"invalid choice ";
                break;
        }
    }while(choice);
}