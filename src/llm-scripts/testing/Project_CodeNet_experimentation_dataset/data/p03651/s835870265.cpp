#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, a[maxn];

int main() {
    scanf("%d %d", &n, &K);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), g = __gcd(a[i], g);
    }
    if (K <= *max_element(a + 1, a + n + 1) && !(K % g)) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}