#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long h,w,n;
    cin>>h>>w>>n;
    
    if(h>w){
        cout<<ceil((double)n/h)<<endl;
    }else{
        cout<<ceil((double)n/w)<<endl;
    }
}
