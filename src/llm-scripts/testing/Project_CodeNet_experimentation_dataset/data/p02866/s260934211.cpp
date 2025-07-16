#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const ll mod = 998244353;

int main() {
    ll n; cin >> n;
    Vl d(n);
    rep(i, 0, n) cin >> d[i];
    if(d[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    map<ll, ll> cnt;
    rep(i, 0, n) cnt[d[i]]++;

    ll si = sz(cnt);
    rep(i, 0, si) if(cnt[i] == 0) {co(0); return 0;}
    if(cnt[0] != 1) {co(0); return 0;}
    if(d[0] != 0) {co(0); return 0;}

    ll ans = 1;
    rep(i, 0, si){
        // ans *= RepeatSquaring(cnt[i], cnt[i+1], mod);
        ans *= modpow(cnt[i], cnt[i+1], mod);
        ans %= mod;
    }
    co(ans);

    return 0;
}
