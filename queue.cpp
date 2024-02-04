
#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, MAX_SIZE;

public:
    Queue(int size) {
        MAX_SIZE = size;
        arr = new int[MAX_SIZE];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        //return (rear + 1) % MAX_SIZE == front ? true : false;
        return rear==MAX_SIZE-1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            // rear = (rear + 1) % MAX_SIZE; 
            ++rear;   
        }
        arr[rear] = value;
        cout<<value<<" enqueued into queue \n";
       
    }

     int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        } else if (front == rear) {
            int dequeued = arr[front];
            front = rear = -1;
            return dequeued;
        } else {
            int dequeued = arr[front];
            front++;
            return dequeued;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to display.\n";
            return;
        }

        int i = front;
        cout << "Elements in the queue: ";
        while (i <= rear) {
            cout << arr[i] << " ";
            i++;
        }
        cout<< endl;
    }

   
};

int main() {
    int size,choice,value;
    cout << "Enter the maximum size of the queue: ";
    cin >> size;

    Queue q(size);

    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                cout<<"dequeue element "<<q.dequeue()<<endl;
                break;
            case 3:
                cout << "Front element: " << q.peek() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid choice.\n";
        }
    } while (choice != 5);
    

    return 0;
}
