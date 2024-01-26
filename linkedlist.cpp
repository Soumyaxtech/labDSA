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
            return;
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
    void deleteHead(){
        if(head==NULL){
            cout<<"the linked-list is empty can't delete anything ";
            return;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    void deleteEnd(){
        if(head==NULL){
            cout<<"the linked-list is empty can't delete anything ";
            return;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }
        Node*temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;
    }
     void deleteAny(int pos){
        if(pos==1){
            deleteHead();
            return;
        }
        else{
            Node*temp=NULL;
            Node*curr=head;
            int count=1;
            while(count<pos){
                temp=curr;
                curr=curr->next;
                count++;           
                }
            temp->next=curr->next;
            curr->next=NULL;
            delete curr;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"the linked-list is empty can't display anything ";
            return;
        }
        Node*temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    bool search(int val){
        Node*temp=head;
        while(temp!=NULL){
            if(temp->data==val){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

};

int main(){
    int choice,val,pos;
    linkedlist l1;
    do{
        cout<<"LINKED-LIST OPERATIONS\n1. insert at head\n2. insert at end\n3. insert at any\n4. delete at head\n5. delete at end\n6. delete at any\n7. display\n8. search\n0. exit\n";
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
                l1.deleteHead();
                cout<<endl;
                break;
            case 5:
                l1.deleteEnd();
                cout<<endl;
                break;
            case 6:
                cout<<"enter the position you want to delete ";
                cin>>pos;
                l1.deleteAny(pos);
                cout<<endl;
                break;
            case 7:
                l1.display();
                cout<<endl;
                break;
            case 8:
                cout<<"enter value to search ";
                cin>>val;
                if(l1.search(val)){
                    cout<<"value present in list "<<endl;
                    break;
                }
                else{
                    cout<<"value not present in list "<<endl;
                    break;
                }
            case 0:
                cout<<"exiting from this code ";
                break;
            default :
                cout<<"invalid input try again ";
                break;
        }
    }while(choice);
}