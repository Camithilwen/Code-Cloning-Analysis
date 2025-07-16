#include <bits/stdc++.h>
int m;
using namespace std;
const int N = 302;
string s;
int f[N][N][N];
int a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    cin >> m;
    for (int i = 0; i < s.size(); i++) a[i + 1] = s[i] - 'a';
    int n = s.size(); a[0] = -1; a[n + 1] = -1;
    f[1][n][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            for (int k = 0; k <= m; k++) {
                f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
                f[i][j - 1][k] = max(f[i][j - 1][k], f[i][j][k]);
                if (a[i] != a[j]) {
                    f[i + 1][j - 1][k + 1] = max(f[i + 1][j - 1][k + 1], f[i][j][k] + 2 - (i == j));
                }
                else {
                    f[i + 1][j - 1][k] = max(f[i + 1][j - 1][k], f[i][j][k] + 2 - (i == j));
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= m; k++) {
                mx = max(mx, f[i][j][k]);
            }
        }
    }
    cout << mx << "\n";
    return 0;
}
