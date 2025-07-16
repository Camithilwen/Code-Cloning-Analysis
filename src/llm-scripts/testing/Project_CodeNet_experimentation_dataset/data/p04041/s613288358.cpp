#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

ll modPow(ll x, ll n) {
    ll ret = 1;
    while(n) {
        if(n&1LL) (ret *= x) %= MOD;
        n >>= 1;
        (x *= x) %= MOD;
    }
    return ret;
}

ll dp[41][(1<<17)+10];

int main(){
    int n;
    vi v(3);
    cin >> n;
    rep(i, 3) cin >> v[i];
    int sum_v = v[0] + v[1] + v[2];
    dp[0][0] = 1;
    auto check = [&](int mask) {
        bool f = true;
        f &= (mask >>=(v[2]-1)) & 1;
        f &= (mask >>=v[1]) & 1;
        f &= (mask >>=v[0]) & 1;
        return f;
    };
    auto pop_mask = [&](int mask) {
        if(mask == 0) return 0;
        bool f = true;
        repr(i, sum_v) {
            if(mask & (1<<i)) {
                if(f) {
                    mask -= (1<<i);
                    f = false;
                    break;
                }
            }
        }
        return mask;
    };
    auto getSize = [&](int mask) {
        if(mask == 0) return 0;
        repr(i, sum_v) {
            if(mask&(1<<i)) {
                return i+1;
            }
        }
        return 0;
    };
    auto push_mask = [&](int mask, int add) {
        if(add > sum_v) return 0;
        while(getSize(mask)+add > sum_v) {
            mask = pop_mask(mask);
        }
        mask <<= add;
        mask |= 1<<(add-1);
        return mask;
    };
    rep(i, n) rep(mask, 1<<sum_v) {
        REP(k, 1, 11) {
            int nxt = push_mask(mask, k);
            if(check(mask) || check(nxt)) continue;
            (dp[i+1][nxt] += dp[i][mask]) %= MOD;
        }
    }
    ll sum = 0LL;
    rep(mask, 1<<sum_v) (sum += dp[n][mask]) %= MOD;
    ll ans = modPow(10, n);
    (ans += MOD - sum) %= MOD;
    cout << ans << endl;
    return 0;
}