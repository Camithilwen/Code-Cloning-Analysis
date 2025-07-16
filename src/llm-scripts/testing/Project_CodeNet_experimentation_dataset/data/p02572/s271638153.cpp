#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
ll ar[N], sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        sum[i] = ar[i];
    }
    for (int i = n - 1; i > 0; i--) {
        sum[i] += sum[i + 1];
        sum[i] %= MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ar[i] * sum[i + 1] % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}