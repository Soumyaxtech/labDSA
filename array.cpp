#include<iostream>

using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void displayAnyPosition(int arr[],int n,int pos){
    if(pos>=1 && pos<=n){
                cout<<"the element of position "<<pos<<" is "<<arr[pos-1];
            }
            else{
                cout<<"invalid position ";
            }
            cout<<endl;
}
void updatePos(int arr[],int n,int pos,int val){
    if(pos>=1 && pos<=n){
        arr[pos-1]=val;
        cout<<"the value of pos "<<pos<<" is updated with "<<val<<endl;
    }
    else{
        cout<<"invalid position "<<endl;
    }
}

int main(){
    int n,choice,pos,val;
    cout<<"enter length of array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element ";
        cin>>arr[i];
    }
    do{
    cout<<endl;
    cout<<"ARRAY-OPERATION\n1.display array elements \n2. display any element\n3. update arrayPos\n0. exit\n";
    cout<<"enter operation you want to perform ";
    cin>>choice;
    switch(choice){
        case 1:
            display(arr,n);
            break;
        case 2:
            cout<<"enter the position ";
            cin>>pos;
            displayAnyPosition(arr,n,pos);
            display(arr,n);
            break;
        case 3:
            cout<<"enter the position ";
            cin>>pos;
            cout<<"enter the val ";
            cin>>val;
            updatePos(arr,n,pos,val);
            display(arr,n);
            break;
        case 0:
            cout<<"exit from this code ";
            break;
        default :
            cout<<"invalid inputs ";
            break;
        }
    }while(choice);
}