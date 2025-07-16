
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

void chmax(ll& a, ll b) {
    if (a < b) a = b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;

    vll A(N);
    REP(i, N) cin >> A[i];

    vector<vll> dp(N, vll(3, -INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = A[0];
    REP(i, N - 1) {
        auto &nxt = dp[i+1], &cur = dp[i];
        if (N & 1) {
            if (i & 1) {
                chmax(nxt[0], cur[1]);
                chmax(nxt[0], cur[2]);
                chmax(nxt[1], cur[0] + A[i+1]);
                chmax(nxt[2], cur[2] + A[i+1]);
            } else {
                chmax(nxt[0], cur[0]);
                chmax(nxt[0], cur[1]);
                chmax(nxt[1], cur[0] + A[i+1]);
                chmax(nxt[2], cur[2]);
            }
        } else {
            if (i & 1) {
                chmax(nxt[0], cur[0]);
                chmax(nxt[0], cur[2]);
                chmax(nxt[2], cur[0] + A[i+1]);
            } else {
                chmax(nxt[0], cur[2]);
                chmax(nxt[2], cur[0] + A[i+1]);
            }
        }
    }

    if (N&1) print(max(dp[N-1][0], dp[N-1][1]));
    else print(max(dp[N-1][0], dp[N-1][2]));

}
