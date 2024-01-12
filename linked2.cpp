#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node* &tail, Node* &head, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        insertAtEnd(tail, d);
        return;
    }
    Node* node2 = new Node(d);
    node2->next = temp->next;
    temp->next = node2;
}

void deleteHead(Node* &head) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }
    Node* prev = head;
    head = head->next;
    delete prev;
}

void deleteEnd(Node* &head, Node* &tail) {
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

void print(Node* &head) {
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

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice, value, position;

    do {
        cout << "Linked List Operations:" << endl;
        cout << "1. Insert at the head" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete the head" << endl;
        cout << "5. Delete the end" << endl;
        cout << "6. Print the list" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the head: ";
                cin >> value;
                insertAtHead(head, value);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                insertAtEnd(tail, value);
                break;
            case 3:
                cout << "Enter the position to insert: ";
                cin >> position;
                cout << "Enter the value to insert at position " << position << ": ";
                cin >> value;
                insertAtPosition(tail, head, position, value);
                break;
            case 4:
                deleteHead(head);
                break;
            case 5:
                deleteEnd(head, tail);
                break;
            case 6:
                // cout << "Current Linked List: ";
                print(head);
                cout << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}
