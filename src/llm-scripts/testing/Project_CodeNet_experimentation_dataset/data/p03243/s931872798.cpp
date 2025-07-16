#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,a[10]={99,111,222,333,444,555,666,777,888,999};
    cin>>n;
    for(i=0;i<10;i++){
        if(a[i]==n){
            cout<<n;
            return 0;
        }

        if(a[i]<n && a[i+1]>n){
        cout<<a[i+1];
        return 0;
        }}
}
