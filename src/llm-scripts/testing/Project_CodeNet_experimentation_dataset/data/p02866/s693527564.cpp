#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=998244353;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
ll pow_mod(ll n,ll k,ll m){
  ll res=1;
  for(;k>0;k>>=1){
    if(k&1){
      res=(res*n)%m;
    }
    n=(n*n)%m;  
  }
  return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin >> n;
    vector<ll> d(n),c(n);
    REP(i,n){
        cin >> d[i];
        c[d[i]]++;
    }
    if(d[0]!=0||c[0]!=1){
        cout << 0 << endl;
        return 0;
    }
    ll ans=1;
    FOR(i,1,n){
        if(!c[i]) continue;
        (ans*=pow_mod(c[i-1],c[i],mod))%=mod;
    }
    cout << ans << endl;
}