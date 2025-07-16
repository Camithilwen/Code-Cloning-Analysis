#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;

typedef long double ld;
typedef vector<ld> vld;

template <class T> void chmin(T& a, T b) { a = min(a, b);}
template <class T> void chmax(T& a, T b) { a = max(a, b);}

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;

int main() {
//	cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vvi a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vll sc(1 << n);
    rep(i, 1 << n) {
        rep(j, n) for(int k = j; k < n; k++) {
            if(!((1 << j) & i && (1 << k) & i)) continue;
            sc[i] += a[j][k];
        }
    }

    vll dp(1 << n, -INFL);
    dp[0] = 0;
    rep(use, 1 << n) {
        int unuse = ((1 << n) - 1) & (~use);
        for(int i = unuse; i > 0; i = (i - 1) & unuse) {
            if(i <= use) continue;
            chmax(dp[use | i], dp[use] + sc[i]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}
