#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], b[MAXN], ans[MAXN];
int L[MAXN], R[MAXN];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l; while (a[r + 1] == a[l] && r < n) r++;
        L[a[l]] = l; R[a[l]] = r;
    }
    int MAX = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l; while (b[r + 1] == b[l] && r < n) r++;
        if (L[b[l]]) {
            MAX = max(MAX, R[b[l]] - l + 1);
        }
    }
    bool fail = 0;
    for (int i = 1; i <= n; i++) {
        ans[(i + MAX - 1) % n + 1] = b[i];
    }
    for (int i = 1; i <= n; i++)
        if (ans[i] == a[i]) fail = 1;
    if (fail) puts("No");
    else {
        puts("Yes");
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}