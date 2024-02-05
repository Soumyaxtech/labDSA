#include<iostream>
using namespace std;
int factorial(int n,int start){
    if(n==1){
        return start;
    }
    else{
        return factorial(n-1,n*start);
    }
}
int main(){
    int n,start;
    cout<<"enter number ";
    cin>>n;
    cout<<"enter starting point ";
    cin>>start;
    cout<<factorial(n,start);
    return 0;
}