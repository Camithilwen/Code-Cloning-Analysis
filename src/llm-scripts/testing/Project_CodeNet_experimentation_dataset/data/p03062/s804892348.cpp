#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define INF 1 << 30;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][1] = -INF;
    ll sum = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) {
        dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
        dp[i+1][1] = max(dp[i][0]-a[i], dp[i][1]+a[i]);
    }

    cout << dp[n][0] << endl;

}