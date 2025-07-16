#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 1e5+5;
int n, m, v, p, a[N], ans; i64 s[N];
int main()
{
    scanf("%d%d%d%d", &n, &m, &v, &p), ans = p;
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    sort(a+1, a+1+n, greater<int>());
    for(int i = 1; i <= n; ++i) s[i] = s[i-1]+a[i];
    for(int i = p+1; i <= n&&a[i]+m >= a[p]; ++i)
        if((i64)m*v <= (p-1ll)*m+(n-i+1ll)*m+i64(i-p)*(a[i]+m)-(s[i-1]-s[p-1])) ++ans; else break;
    printf("%d\n", ans);
    return 0;
}