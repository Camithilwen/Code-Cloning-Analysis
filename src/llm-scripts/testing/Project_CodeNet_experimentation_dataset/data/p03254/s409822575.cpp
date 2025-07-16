#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF = 1LL << 60;

int main() {
    ll N, x;
    cin >> N >> x;

    vector<ll> a(N);
    REP(i, N) cin >> a[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 10, -INF));
    dp[0][0] = 0;
    for(ll i = 1; i <= N; ++i) {
        for(ll sum_cnt = 0; sum_cnt < i; ++sum_cnt) {
            dp[i][sum_cnt] = dp[i - 1][sum_cnt];
            if(i >= 1) {
                chmin(dp[i][sum_cnt], dp[i - 1][sum_cnt - 1] + a[i - 1]);
            }
        }

        dp[i][i] = dp[i - 1][i - 1] + a[i - 1];
    }

    ll ans_i = 0;
    while(ans_i < N && dp[N][ans_i + 1] <= x) {
        ++ans_i;
    }
    if(dp[N][ans_i] < x && ans_i == N) {
        --ans_i;
    }
    cout << ans_i << endl;

    return 0;
}