#include<iostream>

using namespace std;

void bubbleSort(int arr[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                count++;
            }
        }
    }
    cout<<count<<endl;
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
void merge(int arr[],int l,int mid,int r){
    int n1=(mid-l+1);
    int n2=(r-mid);
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(r+l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
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
    cout<<"SORTING OPERATIONS\n1. BUBBLE SORT\n2. INSERTION SORT\n3. MODIFIED-BUBBLE-SORT\n4. SELECTION-SORT\n5. QUICK-SORT\n6. MERGE-SORT\n0.exit\n";
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
        case 6:
            mergeSort(arr,0,n-1);
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