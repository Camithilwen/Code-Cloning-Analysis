#include <iostream>
#include <algorithm>
#include <stdlib.h>   
using namespace std;
int main(void){
    int n;cin>>n;
    
    int a[n];
    for (int i =0;i<n;i++){
        cin>>a[i];
    }
    int sm=0;
    for (int i =0;i<n;i++){
        sm+=a[i];
    }
    
    for (int i =0;i<n;i++){
        a[i]*=n;
    }
    int mn = 1000000;
    int ans =-1;
    for (int i =0;i<n;i++){
        if (mn>abs(sm-a[i])){
            ans = i;
            mn=abs(sm-a[i]);
        }
    }
    cout<<ans;
    
}
