#include<iostream>

using namespace std;
class stack{
    private :
        int cap,top;
        int*arr;
    public :
    stack(int size){
        cap=size;
        top=-1;
        arr= new int[cap];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==cap-1;
    }
    void push(int item){
        if(isFull()){
            cout<<"the stack is full can't push \n";
            return;
        }
        else{
            arr[++top]=item;
            cout<< item << " pushed into stack \n";
            }
    }
    int pop(){
        if(isEmpty()){
            cout<<"the stack is empty can't pop anything \n";
            return -1;
        }
        else{
            return arr[top--];
        }
    }
    int peek(){
        if(isEmpty()){
            cout<<"the stack is empty can't peek anything \n";
            return -1;
        }
        else{
            return arr[top];
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"the stack is empty can't display anything \n";
            return;
        }
        cout<<"THE STACK ELEMENTS ARE ";
        for(int i=top;i>=0;i--){
            cout<< arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int cap,item,choice;
    cout<<"enter the number of element in a stack ";
    cin>>cap;
    stack s1(cap);
    do{
        cout<<"1 push element\n2 pop element\n3 peek element\n4 display element\n0 exit\n";
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
                cout<<s1.peek()<<endl;
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
        do{
            cout<<"DIFFERENT TYPES OF STACK OPERATION \n1 push element \n2 pop element \n3 peek element \n4 display stack element \n0 exit \n";
            cout<<"ENTER THE OPERATION YOU WANT TO PERFORM ";
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"enter the element to push ";
                    cin>>item;
                    s1.push(item);
                    break;
                case 2:
                    cout<<"the pop element is "<<s1.pop()<<endl;
                    break;
                case 3:
                    cout<<"the peek element is "<<s1.peek()<<endl;
                    break;
                case 4:
                    s1.display();
                    break;
                case 0:
                    cout<<"exit from the code........";
                    break;
                default :
                    cout<<"INVALID INPUT TRY A VALID ONE ";
                    break;
            }
        }while(choice);
}