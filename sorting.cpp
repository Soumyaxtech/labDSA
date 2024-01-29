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
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

int pertition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=arr[high]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int k=pertition(arr,low,high);
        quickSort(arr,low,k-1);
        quickSort(arr,k+1,high);
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
    cout<<"SORTING OPERATIONS\n1. BUBBLE SORT\n2. INSERTION SORT\n3. MODIFIED-BUBBLE-SORT\n4. SELECTION-SORT\n5. QUICK-SORT\n0.exit\n";
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
        case 4:
        selectionSort(arr,n);
        cout<<"the sorted array is ";
        break;
        case 5:
            quickSort(arr, 0, n - 1);
            cout << "Array after Quick Sort: ";
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