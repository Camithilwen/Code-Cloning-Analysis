#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200010];
long long f[200010];
long long g[200010];
long long get(int x) {
    if (x <= 0) return 0;
    return f[x];
}
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i) g[i] = g[i-1];
        if (i%2==0) g[i]+= a[i];
    }
    for (i = 0; i < n; i++) {
        if ((i+1)%2==0) {
            f[i]=max(a[i]+get(i-2),g[i-1]);
        } else {
            f[i]=max(a[i]+get(i-2),f[i-1]);
        }
    }
    printf("%lld\n", f[n-1]);
    return 0;
}
