#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
inline int rd(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 5e5+5, oo = 0x3f3f3f3f;
int n, p, q, l[N], r[N], ans; pii v[N];
int main()
{
    n = rd(), p = oo; for(int i = 1; i <= n; ++i) l[i] = rd(), r[i] = rd(), p = min(p, r[i]), q = max(q, l[i]);
    for(int i = 1; i <= n; ++i) v[i].fi = p-l[i]+1, v[i].se = r[i]-q+1, ans = max(ans, r[i]-l[i]+1+max(p-q+1, 0));
    sort(v+1, v+n+1); for(int i = 1, w = oo; i < n; ++i) w = min(w, v[i].se), ans = max(ans, w+v[i+1].fi);
    printf("%d\n", ans);
    return 0;
}