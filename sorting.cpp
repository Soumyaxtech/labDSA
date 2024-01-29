#include<iostream>

using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void ModifiedbubbleSort(int arr[],int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
         swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}
void insertionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int choice,n;
    cout<<"enter the no of element in array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element ";
        cin>>arr[i];
    }
    cout<<"SORTING OPERATIONS\n1. BUBBLE SORT\n2. INSERTION SORT\n3. MODIFIED-BUBBLE-SORT\n0.exit\n";
    cout<<"enter your operation no ";
    cin>>choice;
    cout<<"unsorted array ";
    display(arr,n);
    switch(choice){
        case 1:
        bubbleSort(arr,n);
        cout<<"the sorted array is ";
        break;
        case 2:
        insertionSort(arr,n);
        cout<<"the sorted array is ";
        break;
        case 3:
        ModifiedbubbleSort(arr,n);
        cout<<"the sorted array is ";
        break;
        case 0:
        cout<<"exit from the code ";
        break;
        default :
        cout<<"invalid input ";
        break;
    }
    display(arr,n);
}