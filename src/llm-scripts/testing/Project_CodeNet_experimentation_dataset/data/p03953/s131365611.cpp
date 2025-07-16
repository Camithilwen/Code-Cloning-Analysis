// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
typedef long long int64;
using namespace std;
inline int64 read(int f = 1, int64 x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, m, a[N], f[N], s[N], top, vis[N];
int64 ans[N], k;
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    for(int i = n; i; --i) a[i] -= a[i-1], f[i] = i;
    m = read(), k = read();
    for(int i = 1, p; i <= m; ++i) p = read(), swap(f[p], f[p+1]);
    for(int i = 1; i <= n; ++i, top = 0)
        if(!vis[i])
        {
            for(int j = i; !vis[j]; j = f[j]) vis[j] = 1, s[++top] = j;
            for(int j = 1; j <= top; ++j) ans[s[j]] = a[s[(j+k-1)%top+1]];
        }
    for(int i = 1; i <= n; ++i) printf("%lld\n", ans[i] += ans[i-1]);
    return 0;
}