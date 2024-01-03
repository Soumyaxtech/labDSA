#include<iostream>

using namespace std;
class queue{
        private :
            int front,rear,cap;
            int*arr;
        public :
            queue(int size){
                cap=size;
                front=-1;
                rear=-1;
                arr=new int[cap];
            }
        bool isEmpty(){
            return (rear==-1 && front==-1);
        }
        bool isFull(){
            return (rear==cap-1);
        }
        void enqueue(int item){
            if(isFull()){
                cout<<"the queue is full can't enqueue \n";
                return;
            }
            else if(isEmpty()){
                rear=front=0;
                arr[rear]= item;
            }
            else{
                arr[++rear]=item;
            }
            cout<<item<<" pushed into queue \n";
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"the queue is empty can't dequeue \n";
                return -1;
            }
            else if(front==rear){
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
                cout<<"the queue is empty can't peek\n";
                return -1;
            }
            else{
                return arr[front];
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"the queue is empty can't display \n";
                return;
            }
            cout<<"the queue elements are ";
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
        int cap,item,choice;
        cout<<"enter the no of element present in queue ";
        cin>>cap;
        queue q1(cap);
        do{
            cout<<"1 enqueue element\n2 dequeue element\n3 peek element\n4 display\n0 exit\n";
        cout<<"enter your operation ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter element to enqueue ";
                cin>>item;
                q1.enqueue(item);
                break;
            case 2:
                cout<<"the dequeue element is "<<q1.dequeue()<<endl;
                break;
            case 3:
                cout<<"the element is "<<q1.peek()<<endl;
                break;
            case 4:
                q1.display();
                break;
            case 0:
                cout<<"exiting from the code ";
                break;
            default :
            cout<<"invalid choice ";
            break;
                }
            }
            while(choice);

        
}
