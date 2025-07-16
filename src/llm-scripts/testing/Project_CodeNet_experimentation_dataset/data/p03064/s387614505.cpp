#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))

const int INF = 1000000009;
const int MOD = 998244353;
const int HALF = (MOD + 1) / 2;
const double EPS = 1e-14;
const double PI = acos(-1);

const int MAX = 310;
const int MAX_VAL = MAX*MAX;

int N;
int A[MAX];
ll dp[MAX][MAX_VAL]; // dp[i][x] : i個目まで使ってxをつくるパターン数
ll dp1[MAX_VAL]; // dp1[i] : iをつくるパターン数

ll pw (ll n, ll k) {
    ll r = 1;
    while (k) {
        if (k&1) r = r*n%MOD;
        k >>= 1;
        n = n*n%MOD;
    }
    return r;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    ll ans = pw(3, N);
    int sm = A[0];
    dp[0][0] = 2;
    dp[0][A[0]] = 1;
    FOR (i, 1, N) {
        REP (j, sm+1) if (dp[i-1][j] > 0) {
            dp[i][j] = (dp[i][j] + 2*dp[i-1][j]) % MOD;
            dp[i][j+A[i]] = (dp[i][j+A[i]] + dp[i-1][j]) % MOD;
        }
        sm += A[i];
    }
    int half = sm/2;
    if (sm&1) half++;

    FOR (i, half, sm+1) {
        ans = (ans + 3ll * MOD - 3*dp[N-1][i]) % MOD;
    }

    dp1[0] = 1;
    int mx = 0;
    REP (i, N) {
        REPR (j, mx+1) if (dp[j]) {
            dp1[j+A[i]] = (dp1[j+A[i]] + dp1[j]) % MOD;
        }
        mx += A[i];
    }
    if (sm%2 == 0) ans = (ans + 3*dp1[sm/2]) % MOD;

    cout << ans << endl;
}