#include <bits/stdc++.h>
#define l(i) (n / 2 - (n - i + 1) / 2)
#define r(i) ((i + 1) / 2)
#define st(i) (i / 2 - 1)
using namespace std;
typedef long long ll;
int n, a[200005];
ll dp[200005][3], ans = -1e16;  // j�ķ�Χ��i/2-1��(i+1)/2�����3��
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++) dp[i][j] = -1e16;
    dp[1][1 - st(1)] = a[1], dp[1][0 - st(1)] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = l(i); j <= r(i); j++) {
            if (j == 0)
                dp[i][j - st(i)] = 0;
            else {
                for (int k = i - 2; l(k) <= j - 1 && r(k) >= j - 1 && k >= 0;
                     k--)
                    dp[i][j - st(i)] =
                        max(dp[i][j - st(i)], dp[k][j - 1 - st(k)] + a[i]);
            }
        }
    }
    for (int i = n / 2; i <= n; i++)
        for (int j = l(i); j <= r(i); j++)
            if (j == n / 2) ans = max(ans, dp[i][j - st(i)]);
    cout << ans;
    return 0;
}
