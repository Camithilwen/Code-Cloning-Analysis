#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k, d[4019][4019] = {1}, p[4019] = {1};
    cin >> k >> n;
    for (int i = 1; i <= 4000; i++) {
        d[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            if (d[i][j] >= 998244353) d[i][j] -= 998244353;
        }
        p[i] = p[i - 1] + p[i - 1];
        if (p[i] >= 998244353) p[i] -= 998244353;
    }
    for (int i = 2; i <= k + k; i++) {
        ll z = 0;
        int a, b, c;
        if (i % 2) c = 0;
        else c = 1;
        if (i <= k) b = (i - 1) / 2;
        else b = (k + k + 1 - i) / 2;
        a = k - b - b - c;
        //cout << a << ' ' << b << ' ' << c << ' ';
        for (int j = 0; j <= b; j++) {
            if (n >= j) z = (z + 1ll * d[n + a - 1][n - j] * d[b][j] % 998244353 * p[j]) % 998244353;
            if (c && n > j) z = (z + 1ll * d[n + a - 2][n - j - 1] * d[b][j] % 998244353 * p[j]) % 998244353;
        }
        cout << z << '\n';
    }
}
