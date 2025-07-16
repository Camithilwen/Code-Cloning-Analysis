#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n), dp(n), os(n);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; ++i) {
        os[i] = (i ? os[i-1] : 0) + (i % 2 ? 0 : a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i) dp[i] = a[i] + (i > 1 ? dp[i-2] : 0);
        if (i % 2) {
            dp[i] = max(dp[i], os[i-1]);
        } else if (i){
            dp[i] = max(dp[i], dp[i-1]);
        }
    }
    cout << dp[n-1];
}