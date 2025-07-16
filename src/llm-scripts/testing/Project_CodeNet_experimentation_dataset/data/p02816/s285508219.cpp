#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5, LOG = 30;
int A[N], B[N], cnt[N], f[N], w[N], n;
bool a[N], b[N];

void Check() {
    int curr = 0;
    for (int i = 2; i <= n; i ++) {
        while (curr && b[curr] != b[i - 1]) curr = f[curr];
        if (b[curr] == b[i - 1]) curr++;
        f[i] = curr;
    }
    curr = 0;
    for (int i = 1; i <= n; i++) {
        while (curr && b[curr] != a[i - 1]) curr = f[curr];
        if (b[curr] == a[i - 1]) curr++;
    }
    memset(w, 0, sizeof w);
    while (curr) w[curr] = 1, curr = f[curr];
    w[0] = 1;
    for (int i = 2; i <= n; i ++) {
        while (curr && a[curr] != a[i - 1]) curr = f[curr];
        if (a[curr] == a[i - 1]) curr++;
        f[i] = curr;
    }
    curr = 0;
    for (int i = 1; i <= n; i++) {
        while (curr && a[curr] != b[i - 1]) curr = f[curr];
        if (a[curr] == b[i - 1]) curr++;
    }
    while (curr) {
        if (w[n - curr] == 1) cnt[curr]++;
        curr = f[curr];
    }
    if (w[n] == 1) cnt[0]++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int j = 0; j < LOG; j++) {
        for (int i = 0; i < n; i++) a[i] = (A[i]>>j)&1, b[i] = (B[i]>>j)&1;
        Check();
        for (int i = 0; i < n; i++) a[i] ^= 1;
        Check();
    }
    for (int i = 0; i < n; i++) if (cnt[i] == LOG) cout << i << " " << (A[i]^B[0]) << "\n";
    return 0;
}
