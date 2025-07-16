#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = (int)1e5 + 5, LOG = 60;
int n, x[N], m, a[N], d[N], per[N], jump[N][LOG], finalPos[N], updPos[N], finalD[N];
ll K, ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", x + i);
    scanf("%d %lld", &m, &K);
    for (int i = 1; i <= m; ++i) scanf("%d", a + i);

    for (int i = 1; i <= n; ++i) d[i] = x[i] - x[i - 1];

    for (int i = 1; i <= n; ++i) per[i] = i;
    for (int i = 1; i <= m; ++i) swap(per[ a[i] ], per[ a[i] + 1 ]);
    for (int i = 1; i <= n; ++i) jump[ per[i] ][0] = i;

    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) jump[i][j] = jump[ jump[i][j - 1] ][j - 1];
    }

    for (int i = 1; i <= n; ++i) finalPos[i] = i;
    for (int j = LOG - 1; j >= 0; --j) if ( (K >> j) & 1) {
        for (int i = 1; i <= n; ++i) updPos[i] = jump[ finalPos[i] ][j];
        swap(finalPos, updPos);
    }

    for (int i = 1; i <= n; ++i) finalD[ finalPos[i] ] = d[i];

    for (int i = 1; i <= n; ++i) cout << (ans[i] = ans[i - 1] + finalD[i]) << '\n';

    return 0;
}
