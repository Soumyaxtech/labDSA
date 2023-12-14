#include<iostream>
using namespace std;

class stack{
    private :
        int top;
        int cap;
        int* arr;
    public :
    stack(int cap){
         this->cap=cap;
         this->top=-1;
         this->arr=new int[cap];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==cap-1;
    }
    void push(int item){
        if(isFull()){
            cout<<"the stack is full(overflow)";
            return;
        }
        arr[++top]=item;
        cout<<item<<" pushed into stack\n";
    }
    void display(){
        if(isEmpty()){
            cout<<"the stack is empty(underflow)\n";
            return;
        }
        cout<<"the stack elements are ";
        for(int i=top;i>=0;--i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int pop(){
        if(isEmpty()){
            cout<<"the stack is empty(underflow)\n";
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(isEmpty()){
            cout<<"the stack is empty(underflow)\n";
            return -1;
        }
        return arr[top];
    }
       
};
int main(){
    int cap,choice,item;
    cout<<"enter no of element in stack ";
    cin>>cap;
    stack s1(cap);
    do{
        cout<<"\n1 push element\n2 pop element\n3 peek element\n4 display element\n0 exit\n";
        cout<<"enter your operation ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter element to push ";
                cin>>item;
                s1.push(item);
                break;
            case 2:
                cout<<s1.pop()<<endl;
                break;
            case 3:
                cout<<s1.peek();
                break;
            case 4:
                s1.display();
                break;
            case 0:
                cout<<"exiting from the code ";
                break;
            default :
            cout<<"invalid choice ";
            break;
        }
    }while(choice);
}