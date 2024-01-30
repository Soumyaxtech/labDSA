#include<iostream>
using namespace std;

class Node{
    public:
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
    bool isEmpty(){
        return head==NULL;
    }
    void push(int item){
        Node*temp=new Node(item);
        if(head==NULL){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    int pop(){
        if(isEmpty()){
            cout<<"the stack is empty ";
            return -1;
        }
        else{
            Node*temp=head;
            head=head->next;
            temp->next=NULL;
            int k=temp->data;
            delete temp;
            return k;
        }
    }
    int peek(){
         if(isEmpty()){
            cout<<"the stack is empty ";
            return -1;
        }
        else{
            Node*temp=head;
            return temp->data;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"the stack is empty ";
            return;
        }
        else{
            Node*temp=head;
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    int choice,item,pos;
    linkedlist l1;
    do{
        cout<<"STACK IMPLIMENTATION USING LINKEDLIST\n1. push operation\n2. pop operation\n3. peek operation\n0. exit\n";
        cout<<"enter operation you want to perform ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the element you want to insert ";
                cin>>item;
                l1.push(item);
                l1.display();
                break;
            case 2:
                cout<<l1.pop()<<endl;
                l1.display();
                cout<<endl;
                break;
            case 3:
                cout<<l1.peek()<<endl;
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