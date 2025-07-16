#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
        a[i] %= m;
    }
    vector<ll>r(n+1,0);
    map<ll,ll>mp;
    mp[0]++;
    rep(i,n){
        r[i+1] = r[i]+a[i];
        r[i+1] %= m;
        mp[r[i+1]]++;
    }
    ll ans = 0;
    for(auto it = mp.begin();it!=mp.end();it++){
        ll now = it->second;
        ans += (now-1)*now/2;
    }
    cout << ans << endl;
    return 0;
}
