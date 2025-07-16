#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll k,x;
    cin>>k>>x;
    ll n=k-1;
    for(ll i=x-n;i<=x+n;i++){
        cout<<i<<" ";
    }
    cout<<endl;

}
