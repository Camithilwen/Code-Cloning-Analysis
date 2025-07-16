#include<iostream>
#include<math.h>
using namespace std;
int isPrime(int n){
    if(n<2)return 0;
    double sqrtn= sqrt(n);
    for(int i=2;i<=sqrtn;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(void){
    int n=1;
    while(n){
        cin>>n;
        for(int i=n;i>0;i--){
            if(isPrime(i)*isPrime(i-2)){
                cout<<i-2<<" "<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
