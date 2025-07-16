#include<iostream>
#include<math.h>
using namespace std;
int maxn=1000;
int main(){
    int A[maxn];
    double a,b=0,c=0,d=0,e=0,f=0,g=0,w=0,x=0,y=0,z=0;
    for(int i=0;i!=6;i++){
        cin>>a;
        A[i]=a;
    }
    for(int i=4;i!=0;i--){
        b=abs(A[0]-A[i]);
        if(b>A[5]){cout<<":("; return 0;}
        b=0;
    }

    for(int i=4;i!=1;i--){
        b=abs(A[1]-A[i]);
        if(b>A[5]){cout<<":("; return 0;}
        b=0;
    }

    for(int i=4;i!=2;i--){
        b=abs(A[2]-A[i]);
        if(b>A[5]){cout<<":("; return 0;}
        b=0;
    }

    for(int i=4;i!=3;i--){
        b=abs(A[3]-A[i]);
        if(b>A[5]){cout<<":("; return 0;}
        b=0;
    }
    cout<<"Yay!";
    return 0;
}
