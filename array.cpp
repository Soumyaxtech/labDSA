#include<iostream>

using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,choice,pos;
    cout<<"enter length of array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element ";
        cin>>arr[i];
    }
    do{
    cout<<endl;
    cout<<"ARRAY-OPERATION\n1.display array elements \n2. display any element\n0. exit\n";
    cout<<"enter operation you want to perform ";
    cin>>choice;
    switch(choice){
        case 1:
            display(arr,n);
            break;
        case 2:
            cout<<"enter the position ";
            cin>>pos;
            if(pos>=1 && pos<=n){
                cout<<"the element of position "<<pos<<" is "<<arr[pos-1];
            }
            else{
                cout<<"invalid position ";
            }
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