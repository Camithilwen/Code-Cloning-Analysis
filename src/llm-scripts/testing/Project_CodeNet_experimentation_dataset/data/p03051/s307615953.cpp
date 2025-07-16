#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;
typedef vector<VD> VVD;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 1e9 + 7;

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
    x %= mod;
    ll res = 1LL;
    while(y){
        if (y & 1LL)
            res *= x;
        res %= mod;
        x = (x*x) % mod;
        y >>= 1LL;
    }
    return res;
}

ll naive(VI a, int x){
    // cout << "naive" << endl;
    int n = a.size();
    VVL dp(n + 1, VL(2));
    dp[0][0] = 1;
    int y = 0;
    REP(i,n){
        y ^= a[i];
        if (y == x){
            REP(j,i+1) dp[i+1][1] += dp[j][0];
        }
        if (y == 0){
            REP(j,i+1) dp[i+1][0] += dp[j][1];
        }
        // cout << dp[0] << " " << dp[1] << endl;
    }
    // REP(i,n+1) cout << dp[i][0] << " " << dp[i][1] <<endl;

    return dp[n][0];
}

ll calc(VL a, VL b){
    int n = a.size();
    if (n == 1) return a[0];
    VL dp(n);
    dp[0] = a[0];
    ll sum = dp[0], tmp = 0;
    REP(i,n-1){
        tmp = (tmp + b[i] * sum) % mod;
        dp[i + 1] = ((tmp + 1) * a[i + 1]) % mod;
        sum = (sum + dp[i + 1]) % mod;
    }
    ll ret = 0;
    REP(i,n) ret = (ret + dp[i]) % mod;
    return ret;
}

int main() {
    int n;
    cin >> n;
    VI a(n);
    int x = 0;
    REP(i,n){
        a[i] = in();
        x ^= a[i];
    }

    if (x != 0){
        VL dp(2);
        dp[0] = 1;
        int y = 0;
        REP(i,n){
            y ^= a[i];
            if (y == x){
                dp[1] = (dp[1] + dp[0]) % mod;
            }
            if (y == 0){
                dp[0] = (dp[0] + dp[1]) % mod;
            }
        }
        cout << dp[0] << endl;
        return 0;
    }

    ll cnt = 0;
    int j = 0;
    map<int, VL> mpc, mpl;
    map<int, int> last;
    REP(i,n){
        x ^= a[i];
        if (x == 0){
            map<int, ll> tmp;
            int p = 0;
            FOR(k,j,i-1){
                p ^= a[k];
                tmp[p]++;
            }
            // FOR(k,j,i){
            //     cout << a[k] << " ";
            // }
            // cout << endl;
            for (auto hoge : tmp){
                int p = hoge.first;
                ll c = hoge.second;
                mpc[p].push_back(c);
                if (last.count(p)){
                    mpl[p].push_back(cnt - last[p]);
                }
                last[p] = cnt;
            }
            cnt++;
            j = i + 1;
        }
    }

    // cout << cnt << " " << powll(2, cnt - 1) << endl;

    ll ans = powll(2, cnt - 1);
    for (auto tmp : mpc){
        int x = tmp.first;
        // cout << "x" << x << endl;
        // for (int c : mpc[x]) cout << c << " ";
        // cout << endl;
        // for (int l : mpl[x]) cout << l << " ";
        // cout << endl;
        // cout << naive(a, x) << endl;

        ans = (ans + calc(mpc[x], mpl[x])) % mod;
    }
    cout << ans << endl;
    return 0;
}
