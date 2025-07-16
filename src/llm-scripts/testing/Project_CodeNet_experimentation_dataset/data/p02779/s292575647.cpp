#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);

    bool ok = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) ok = 0;
    }

    if (ok) printf("YES\n");
    else printf("NO\n");
}
