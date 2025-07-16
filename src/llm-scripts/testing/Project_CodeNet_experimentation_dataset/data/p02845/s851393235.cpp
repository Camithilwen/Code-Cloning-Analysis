#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll MOD = pow(10, 9) + 7;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]++;
    }

    vector<ll> dp(N, 0);
    ll ans = 1;
    dp[0] = 3;

    for (int i = 0; i < N; i++) {
        if (dp[A[i] - 1] == 0) {
            cout << 0 << endl;
            return 0;
        }

        ans *= dp[A[i] - 1];
        ans %= MOD;
        dp[A[i] - 1]--;
        dp[A[i]]++;
    }

    cout << ans << endl;
}
