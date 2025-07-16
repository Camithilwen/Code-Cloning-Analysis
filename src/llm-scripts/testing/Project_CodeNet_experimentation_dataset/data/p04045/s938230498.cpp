#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll n,k;
    cin>>n>>k;
    char d[k];
    rep(0,i,k)cin>>d[i];
    rep(n,N,100001){
        string nN=to_string(N);
        bool t=true;
        rep(0,i,nN.length()){
            rep(0,j,k){
                if(d[j]==nN[i])t=false;
            }
        }
        //cout<<nN<<" "<<t<<endl;
        if(t==true){
            cout<<nN;
            return 0;
        }
    }
}