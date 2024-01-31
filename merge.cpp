#include<iostream>

using namespace std;

void merge(int arr[],int l,int mid,int r){
 int n1=(mid-l+1);
 int n2=(r-mid);
 int arr1[n1],arr2[n2];
 for(int i=0;i<n1;i++){
    arr1[i]=arr[l+i];
 }
 for(int i=0;i<n2;i++){
    arr2[i]=arr[mid+1+i];
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
    k++;
    i++;
 }
 while(j<n2){
    arr[k]=arr2[j];
    k++;
    j++;
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
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element ";
        cin>>arr[i];
    }
    cout<<"the unsorted array is ";
    display(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"the sorted array is ";
    display(arr,n);

}