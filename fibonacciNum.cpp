#include<iostream>

using namespace std;
int fibonacci(int n,int prev,int curr){
    if(n==0){
        return prev;
    }
    else if(n==1){
        return curr;
    }
    cout<<prev;
    return fibonacci(n-1,curr,curr+prev);
}
int main(){
    int n;
    cout<<"enter number ";
    cin>>n;
    fibonacci(n+1,0,1);
    return 0;
}