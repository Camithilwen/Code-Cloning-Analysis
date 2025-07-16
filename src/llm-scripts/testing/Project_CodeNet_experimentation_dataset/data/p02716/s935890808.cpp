#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<long>> d(n + 1, vector<long>(5, LLONG_MIN));
    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            int k = (i + 1) / 2 - j;
            if (k < 0) continue;
            {
                // don't take i-th
                int ii = i - 1;
                int jj = (ii + 1) / 2 - k;
                if (jj >= 0 && jj < 5) {
                    if (d[ii][jj] != LLONG_MIN) {
                        d[i][j] = max(d[i][j], d[ii][jj]);
                    }
                }
            }
            if (k > 0) {
                // take i-th, don't take i-1-th
                int ii = i == 1 ? 0 : i - 2;
                int jj = (ii + 1) / 2 - (k - 1);
                if (jj >= 0 && jj < 5) {
                    if (d[ii][jj] != LLONG_MIN) {
                        d[i][j] = max(d[i][j], d[ii][jj] + a[i - 1]);
                    }
                }
            }
        }
    }
    int k = n / 2;
    int j = (n + 1) / 2 - k;
    cout << d[n][j];

    return 0;
}