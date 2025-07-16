#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int MOD = 998244353;

int dp[305][100000];
int dp2[305][100000];
int n, a[305];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    int sum  = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    bool flag = (sum % 2 == 0);
    sum = (sum - 1) / 2 + 1;
    dp[0][0] = 1;
    dp2[0][0] = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = 1LL * ans * 3 % MOD;
        for (int j = 0; j <= 90000; j++) {
            dp2[i][j] = dp2[i - 1][j];
            dp[i][j] = dp[i - 1][j] * 2 % MOD;
            if (j >= a[i]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % MOD;
                dp2[i][j] = (dp2[i][j] + dp2[i - 1][j - a[i]]) % MOD;
            }
        }
    }
    int tmpAns = 0;
    for (int i = sum; i <= 90000; i++) {
        tmpAns = (tmpAns + dp[n][i]) % MOD;
    }
    tmpAns = 1LL * tmpAns * 3 % MOD;
    if (flag) tmpAns = (tmpAns - 3LL * dp2[n][sum]) % MOD;
    if (tmpAns < 0) tmpAns += MOD; 
    ans = (ans - tmpAns) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans;
    return 0;
}