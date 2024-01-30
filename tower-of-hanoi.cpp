#include<iostream>
using namespace std;

void TowerOfHanoi(int start,int end,char sour,char aux,char dest){
    if(start>end){
        return;
    }
    else{
        TowerOfHanoi(start,end-1,sour,dest,aux);
        cout<<"move "<<end<<" from "<<sour<<" to "<<dest<<endl;
        TowerOfHanoi(start,end-1,aux,sour,dest);
    }
}

int main(){
    TowerOfHanoi(1,3,'A','B','C');
}