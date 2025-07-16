#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,d,k=1;
    long long minx=10000;
    cin>>n;
    while(1){
        d=n/k%1000;
        if(d<100){
            break;
        }
        else if(abs(753-d)<minx){
            minx=abs(753-d);
        }
        k*=10;
        
    }
    cout<<minx<<endl;
    return 0;
}
