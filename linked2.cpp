#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
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
void insertAtHead(int d) {
    Node* temp = new Node(d);
    if(head==NULL){
        head=tail=temp;
    }
    // Node* temp = new Node(d);
    else{
    temp->next = head;
    head = temp;
}
}

void insertAtEnd(int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(int pos, int d) {
    if (pos == 1) {
        insertAtHead(d);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp ->next== NULL) {
        insertAtEnd(d);
        return;
    }
    Node* node2 = new Node(d);
    node2->next = temp->next;
    temp->next = node2;
}

void deleteHead() {
    if (head == NULL) {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    if (head == tail) {
        // Only one node in the list
        delete head;
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
}
void deleteAny(int pos){
        if(pos==1){
            deleteHead();
            return;
        }
        else{
            Node*prev=NULL;
            Node*curr=head;
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
void print() {
    if(head==NULL){
        cout<<"linkedlist is empty ";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
};
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    linkedlist l1;
    int choice, value, position;
    do {
        cout << "Linked List Operations:" << endl;
        cout << "1. Insert at the head" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete the head" << endl;
        cout << "5. Delete the end" << endl;
        cout<<"6. Delete any position"<<endl;
        cout << "7. Print the list" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the head: ";
                cin >> value;
                l1.insertAtHead(value);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                l1.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter the position to insert: ";
                cin >> position;
                cout << "Enter the value to insert at position " << position << ": ";
                cin >> value;
                l1.insertAtPosition(position,value);
                break;
            case 4:
                l1.deleteHead();
                break;
            case 5:
                l1.deleteEnd();
                break;
            case 6:
                cout<<"enter the position you want to delete ";
                cin>>position;
                l1.deleteAny(position);
                break;
            case 7:
                // cout << "Current Linked List: ";
                l1.print();
                cout << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice);

    return 0;
}
