#include<iostream>

using namespace std;
class Node{
    public :
        int data;
        Node*next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};
class circular{
    private :
        Node*head;
        Node*tail;
    public :
        circular(){
            this->head=NULL;
            this->tail=NULL;
        }
    void insertAtHead(int val){
        Node*temp=new Node(val);
        if(head==NULL){
        head=tail=temp;
        temp->next=head;
        return;
        }
        else{
            temp->next=head;
            head=temp;
            tail->next=temp;
        }
    }
    void insertAtEnd(int val){
        Node*temp=new Node(val);
        if(tail==NULL){
            tail=temp;
            temp->next=head;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
            temp->next=head;
        }
    }
    void insertAny(int pos,int val){
        if(pos==1){
            insertAtHead(val);
            return;
        }
        Node*temp=head;
        int count=1;
        while(count<pos-1 && temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            insertAtEnd(val);
            return;
        }
        Node*node2=new Node(val);
        node2->next=temp->next;
        temp->next=node2;
    }
    void display(){
        if(head==NULL){
            cout<<"the list is empty"<<endl;
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
    int choice,val,pos;
    circular c1;
    do{
       cout<<"CIRCULAR-LINKEDLIST OPERATIONS\n1. insert at head\n2. insert at tail\n3. insert any\n0. exit\n";
    cout<<"enter the operation you want to perform ";
    cin>>choice; 
    switch(choice){
        case 1:
            cout<<"enter the element ";
            cin>>val;
            c1.insertAtHead(val);
            c1.display();
            break;
        case 2:
             cout<<"enter the element ";
            cin>>val;
            c1.insertAtEnd(val);
            c1.display();
            break;
        case 3:
            cout<<"enter the position of inserting ";
                cin>>pos;
                cout<<"enter the element you want to insert ";
                cin>>val;
                c1.insertAny(pos,val);
                c1.display();
                break;
        case 0:
            cout<<"exit from the code";
            break;
        default :
        cout<<"invalid choice ";
        break;
    }
    }while(choice);
}



