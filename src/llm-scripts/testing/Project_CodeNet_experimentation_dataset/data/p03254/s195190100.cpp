#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    
    for(int p=0;p<testcase;p++){
    ll n=0,x=0;
    cin>>n>>x;
    ll array[n]={0};
	ll totalsum=0;
    for(int i=0;i<n;i++){
    cin>>array[i];
    totalsum+=array[i];
    }
    if(totalsum<x){
        cout<<n-1;
    }
else if(totalsum==x)
cout<<n;
    else
    {
        sort(array,array+n);
        ll counter=0;
        ll sum=x;
        ll i=0;
        while(sum>=0){
       // cout<<array[i];
        sum-=array[i];
    	if(sum<0)
    	break;        
	    i++;
        counter++;
        }
        cout<<counter;
    }
     
    
    
    
        
    }

    return 0;
}
