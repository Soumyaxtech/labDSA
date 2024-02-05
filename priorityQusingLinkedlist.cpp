#include<iostream>
using namespace std;

class Node{
    public:
        int data,priority;
        Node*next;
    Node(int size,int prio){
        this->data=size;
        this->priority=prio;
        this->next=NULL;
    }
};
class Prairoty{
    private:
        Node*head;
        Node*tail;
    public:
        Prairoty(){
            this->head=NULL;
            this->tail=NULL;
        }

    bool isEmpty(){
        return(head==NULL);
    }
        void enqueue(int item, int priority) {
        Node* temp = new Node(item, priority);

        if (head == NULL) {
            head = tail = temp;
            return;
        } else if (head == tail) {
            if (head->priority > priority) {
                temp->next = head;
                head = temp;
            } else {
                head->next = temp;
                tail = temp;
            }
        } else {
            if (priority < head->priority) {
                temp->next = head;
                head = temp;
            } else {
                Node* curr = head;
                while (curr->next != NULL && priority > curr->next->priority) {
                    curr = curr->next;
                }
                temp->next = curr->next;
                curr->next = temp;
                if (curr == tail) {
                    tail = temp;
                }
            }
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"the queue is empty can't dequeue ";
            return -1;
        }
        else{
            Node*temp=head;
            head=head->next;
            int k=temp->data;
            temp->next=NULL;
            delete temp;
            return k;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"the queue is empty can't display ";
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
    int choice,item,priority;
    Prairoty p1;
    do{
        cout<<"1. insert\n2. display\n3. dequeue\n4. is empty\n0. exit\n";
        cout<<"enter the operation ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the element ";
                cin>>item;
                cout<<"enter priority ";
                cin>>priority;
                p1.enqueue(item,priority);
                p1.display();
                break;
            case 2:
                p1.display();
                break;
            case 3:
                cout<<p1.dequeue()<<endl;
                p1.display();
                break;
            case 4:
                if(p1.isEmpty()){
                    cout<<"the queue is empty "<<endl;
                    break;
                }
                else{
                    cout<<"the queue is not empty "<<endl;
                    break;
                }
            case 0:
                cout<<"exiting from this code ";
                break;
            default :
                cout<<"invalid inputs ";
                break;
        }
    }while(choice);
}