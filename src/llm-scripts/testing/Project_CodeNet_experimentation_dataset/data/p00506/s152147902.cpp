#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    ll n; cin>>n;
    if(n==2){
        ll a,b; cin>>a>>b;
        ll x=gcd(a,b);
        rep(i,x+1){
            if(i==0)continue;
            if(x%i==0) cout<<i<<endl;
        }
    }else{
        ll a,b,c; cin>>a>>b>>c;
        ll x=gcd(a,b);
        ll y=gcd(c,x);
        rep(i,y+1){
            if(i==0)continue;
            if(y%i==0) cout<<i<<endl;
        }
    }
    return 0;
}
