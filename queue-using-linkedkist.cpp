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
    void enqueue(int item){
        Node*temp=new Node(item);
        if(head==NULL){
            head=tail=temp;
            return;
        }
        else{
            tail->next=temp;
                tail=temp;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"the queue is empty ";
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
            cout<<"the queue is empty ";
            return -1;
        }
        else{
            Node*temp=head;
            return temp->data;
        }
    }
    void display(){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    int choice,item;
    linkedlist l1;
    do{
        cout<<"QUEUE USING LINKEDLIST OPERATIONS\n1. enqueue\n2. dequeue\n3. peek\n4. display\n0. exit\n";
        cout<<"enter your operation ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter element to enqueue ";
                cin>>item;
                l1.enqueue(item);
                l1.display();
                break;
            case 2:
                cout<<l1.dequeue()<<endl;
                l1.display();
                break;
            case 3:
                cout<<l1.peek()<<endl;
                l1.display();
                break;
            case 4:
                l1.display();
                break;
            case 0:
                cout<<"exit from the code ";
                break;
            default :
                cout<<"invalid input ";
                break;
        }
    }while(choice);
}