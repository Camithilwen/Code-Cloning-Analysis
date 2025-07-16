#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,r,k;
    cin>>n>>r;
    if(n>=10){
        k=0;
    }else{
        k=1000-100*n;
    }
    cout<<r+k;
}