#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}
 
unordered_map<ll, ll> memo;

ll inv(ll a) {
    if(memo.find(a) != memo.end()) return memo[a];
    ll x, y;
    extgcd(a, MOD, x, y);
    return memo[a] = (x + MOD) % MOD;
}

int main(){
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    ll f[1001];
    f[0]=1;
    rep(i,n) f[i+1]=f[i]*(i+1)%MOD;
    vector<vector<ll>> s(n+1,vector<ll>(n+1,0));
    rep(i,n+1) s.at(0).at(i)=1;
    for (ll i=a;i<=b;i++){
        rep(k,n+1){
        s.at(k).at(i)=s.at(k).at(i-1);
        ll in=1;
        ll invf=inv(f[i]);
        rep(j,c) in=in*invf%MOD;
        for (int j=c;j<=min(d,k/i);j++){
            ll tmp=f[n-k+i*j]*inv(f[n-k])%MOD;
            tmp=tmp*in%MOD;
            in=in*invf%MOD;
            tmp=tmp*inv(f[j])%MOD;
            (s.at(k).at(i)+=s.at(k-i*j).at(i-1)*tmp%MOD)%=MOD;
        }
        }
        
    }
    cout << s.at(n).at(b)%MOD << endl;
}
