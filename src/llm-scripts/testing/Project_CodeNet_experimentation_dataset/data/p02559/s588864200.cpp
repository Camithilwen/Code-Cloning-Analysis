#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll= long long;
using ld= long double;
using vl= vector<ll>;
using vd= vector<ld>;
using vs= vector<string>;
using vb= vector<bool>;
using vvl= vector<vector<ll>>;
using vvd= vector<vector<ld>>;
using vvs= vector<vector<string>>;
using vvb= vector<vector<bool>>;
using pll= pair<ll, ll>;
constexpr ll mod= 1e9 + 7;
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for(ll(i)= 0; (i) < (n); (i)++)
#define REPS(i, n) for(ll(i)= 1; (i) <= (n); (i)++)
#define RREP(i, n) for(ll(i)= (n - 1); (i) >= 0; (i)--)
#define RREPS(i, n) for(ll(i)= (n); (i) > 0; (i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
#define YES(n) ((n) ? "YES" : "NO")
#define Yes(n) ((n) ? "Yes" : "No")
#define yes(n) ((n) ? "yes" : "no")

template <class T>
inline void chmin(T &a, T b) {
    if(a > b) { a= b; }
}

template <class T>
inline void chmax(T &a, T b) {
    if(a < b) { a= b; }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ll N,Q;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    REP(i,N){
        ll x;
        cin >> x;
        fw.add(i,x);
    }
    REP(i,Q){
        ll b;
        cin >> b;
        if(b == 0){
            ll p,t;
            cin >> p >> t;
            fw.add(p,t);
        }else{
            ll l,r;
            cin >> l >> r;
            cout << fw.sum(l,r) << "\n";
        }
    }
}