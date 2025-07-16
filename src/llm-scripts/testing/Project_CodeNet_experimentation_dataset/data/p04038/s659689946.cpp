#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;

#define SIZE 4000001

ll kai[SIZE];
ll mokai[SIZE];

ll mod_pow (ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y&1) ret = ret*x%MOD;
        x = x*x%MOD;
        y /= 2;
    }
    return ret;
}

void init () {
    kai[0] = 1;
    for (int i = 1; i < SIZE; i++) kai[i] = kai[i-1]*i%MOD;
    for (int i = 0; i < SIZE; i++) mokai[i] = mod_pow(kai[i],MOD-2);
}

ll conb (ll x, ll y) {
    ll z = x-y;
    ll ret = kai[x]*mokai[y]%MOD;
    ret = ret*mokai[z]%MOD;
    return ret;
}

ll n, k;
ll dp[2001][2001];

inline ll mmul (ll x, ll y) {
    return x*y%MOD;
}

int main() {
    cin >> n >> k;
    init();
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++) {
        dp[i][0] = mmul(dp[i-1][0], conb(i*(k-1)-1,k-2));
    }
    for (ll j = 1; j <= n; j++) {
        for (ll i = j; i <= n; i++) {
            if (i == j) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = (mmul(dp[i-1][j], conb(i*k-(i-j)-1, k-2)) + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << (dp[n][n] * kai[n]) % MOD;
}
