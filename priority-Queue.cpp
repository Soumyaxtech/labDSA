#include<iostream>

using namespace std;
class Priority{
    private :
        int cap,rear,front;
        int*arr;
    public :
    Priority(int val){
        this->cap=val;
        this->rear=-1;
        this->front=-1;
        this->arr=new int[cap];
    }
    bool isFull(){
        return rear==cap-1;
    }
    bool isEmpty(){
        return(rear==-1 && front==-1);
    }
    void enqueue(int item){
        if(isFull()){
            cout<<"the queue is full can't enqueue "<<endl;
            return;
        }
        else if(isEmpty()){
            rear=front=0;
            arr[rear]=item;
            return;
        }
        else{
             int i = rear;
        while (i >= front && arr[i] > item) {
            arr[i + 1] = arr[i]; // it is for acending priority
            i--;           // for decending only change arr[i]<item
        }
        arr[i + 1] = item;
        rear++;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"the queue is empty can't dequeue"<<endl;
            return -1;
        }
        else if(rear==front){
            int val=arr[front];
            front=rear=-1;
            return val;
        }
        else{
            int val=arr[front];
            front++;
            return val;
        }
    }
    int peek(){
        if(isEmpty()){
            cout<<"the queue is empty can't peek"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"the Queue is empty can't display "<<endl;
            return;
        }
        cout<<"the Queue elements are ";
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int cap,item,choice;
    cout<<"enter length of Queue ";
    cin>>cap;
    Priority p1(cap);
    do{
        cout<<"PRIORITY QUEUE IMPLEMENTATION\n1. enqueue\n2. dequeue\n3. peek\n4. display\n0. exit\n";
        cout<<"enter the operation you want to perform ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the element to enqueue ";
                cin>>item;
                p1.enqueue(item);
                p1.display();
                break;
            case 2:
                cout<<p1.dequeue()<<endl;
                p1.display();
                break;
            case 3:
                cout<<p1.peek()<<endl;
                p1.display();
                break;
            case 4:
                p1.display();
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