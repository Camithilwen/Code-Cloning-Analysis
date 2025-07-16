#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
//typedef pair<ll, ll> P;
const ll INF=1LL<<60;
ll gcd(ll x,ll y){return y? gcd(y,x%y) :x;}
//写し
vector<pair<ll,int>>factorize(ll n){
    vector<pair<ll,int>>res;
    for(ll i=2;i*i<=n;++i){
        if(n%i)continue;
        res.emplace_back(i,0);
        while(n%i==0){
            n/=i;
            res.back().second++;
        }
    }
    if(n!=1)res.emplace_back(n,1);
    return res;
}
int main(){
    ll a,b;
    cin>>a>>b;
    ll g=gcd(a,b);
    auto f=factorize(g);
    int ans=f.size()+1;
    cout<<ans<<endl;
    return 0;
}

