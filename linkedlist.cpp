#include<iostream>

using namespace std;
class Node{
    public :
        int data;
        Node*next;
        Node(int val){
            this->data=val;
            this->next=NULL;
        }
};
class linkedlist{
    private :
        Node*head;
        Node*tail;
    public :
        linkedlist(){
        this->head=NULL;
        this->tail=NULL;
        }
    void insertHead(int val){
        Node*temp=new Node(val);
        if(head==NULL){
            head=tail=temp;
        }
        temp->next=head;
        head=temp;
    }
    void insertEnd(int val){
        Node*temp=new Node(val);
        if(tail==NULL){
            tail=temp;
            return;
        }
        tail->next=temp;
        tail=tail->next;
    }
    void insertAny(int pos,int val){
        if(pos==1){
            insertHead(val);
            return;
        }
        Node*temp=head;
        int count=1;
        while(count<pos-1 && temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            insertEnd(val);
            return;
        }
        Node*node2=new Node(val);
        node2->next=temp->next;
        temp->next=node2;
    }
    void display(){
        if(head==NULL){
            cout<<"the linked-list is empty can't display anything ";
            return;
        }
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    int choice,val,pos;
    linkedlist l1;
    do{
        cout<<"LINKED-LIST OPERATIONS\n1. insert at head\n2. insert at end\n3. insert at any\n4. display\n0. exit\n";
        cout<<"enter operation you want to perform ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the element you want to insert ";
                cin>>val;
                l1.insertHead(val);
                break;
            case 2:
                cout<<"enter the element you want to insert ";
                cin>>val;
                l1.insertEnd(val);
                break;
            case 3:
                cout<<"enter the position of inserting ";
                cin>>pos;
                cout<<"enter the element you want to insert ";
                cin>>val;
                l1.insertAny(pos,val);
                break;
            case 4:
                l1.display();
                cout<<endl;
                break;
            case 0:
                cout<<"exiting from this code ";
                break;
            default :
                cout<<"invalid input try again ";
                break;
        }
    }while(choice);
}