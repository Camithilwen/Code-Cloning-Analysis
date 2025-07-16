#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

const int M = 100010;
ll n;
vll x;
int d[18][M];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cin >> n;
    x.resize(n);
    rep(i, n){
        cin >> x[i];
    }
    ll l;
    cin >> l;
    
    rep(j, n){
        d[0][j] = upper_bound(ALL(x), x[j] + l) - x.begin() - 1;
    }
    repr(i, 1, 18)rep(j, n){
        d[i][j] = d[i-1][d[i-1][j]];
    }
    /*
    rep(i, 18)rep(j, n){
        cout << d[i][j] << " \n"[j+1==n];
    }
    cout << endl;
    */
    ll q;
    cin >> q;
    ll a, b;
    rep(qq, q){
        cin >> a >> b;
        a--;b--;
        if(a > b) swap(a, b);
        ll ans = 0;
        ll p = a;
        while(1){
            rep(i, 18){
                //cout << i << " " << p << endl;
                if(d[i][p] >= b){
                    if(i == 0){
                        ans++;
                        goto enendd;
                    }else{
                        ans += powmod(2, i-1);
                        p = d[i-1][p];
                        break;
                    }
                }
            }
        }
        enendd:
        cout << ans << endl;
    }
    return 0;
}