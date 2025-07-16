#include<bits/stdc++.h>
using ll=long long;
#define rep(i,j,n) for(ll i=(j);i<(n);i++)
#define per(i,n,j) for(ll i=(n);i>=(j);i--)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll l,r;

int main(){
    cin>>l>>r;
    ll ans=INF;
    rep(i,l,min(l+2019,r)){
        rep(j,l+1,min(l+2020,r+1)){
            ll num=(i*j)%2019;
            chmin(ans,num);
        }
    }
    /*if(l%2019==0 ||l%2019>=r%2019 || r-l>=2019) ans=0;
    else{
        ll num;
        num=l%2019*(l+1)%2019;
        if(num<2019) ans=num;
        else ans=num%2019;
    }*/
    cout<<ans<<"\n";
    return 0;
}
