#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll a,b,c;
    cin>>a>>b>>c;
    if(a>b)swap(a,b);
    rep(a,i,b+1){
        if(i==c){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}
