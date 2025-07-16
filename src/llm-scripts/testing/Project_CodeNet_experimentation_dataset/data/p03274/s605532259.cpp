#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    vector<ll> x(n);rep(i,n)cin>>x[i];
    ll ans = INF;
    for(int i=0; i+k-1<n; i++){
        ll l = x[i], r = x[i+k-1];
        ll a;
        if(r<0)a=-l;
        else if(l<0)a=min(r-2*l, 2*r-l);
        else a=r;
        ans = min(ans, a);
    }
    cout<<ans<<endl;
    return 0;
}