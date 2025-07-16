#include <cstring>
#include <cctype>
#include <cstdio>
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e2+5;
int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }
short f[N][N][N][N], g[N][N], h[N][N];
char s[N][N];
int n, m, ans, px, py;
int main()
{
    n = read(), m = read(); memset(f, -1, sizeof(f));
    for(int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(s[i][j] == 'E') px = i, py = j;
            g[i][j] = g[i][j-1]+(s[i][j] == 'o');
            h[i][j] = h[i-1][j]+(s[i][j] == 'o'); 
        }    
    f[0][0][0][0] = 0;    
    int pl = py-1, pr = m-py, pd = px-1, pu = n-px, p;
    for(int l = 0; l <= pl; ++l)
        for(int r = 0; r <= pr; ++r)
            for(int d = 0; d <= pd; ++d)
                for(int u = 0; u <= pu; ++u)
                {
                    if(!(~f[l][r][d][u])) continue;
                    int cl = max(r+1, py-l), cr = min(m-l, py+r);
                    int cd = max(u+1, px-d), cu = min(n-d, px+u);
                    if((p = py+r+1) <= m-l) f[l][r+1][d][u] = max(f[l][r+1][d][u], f[l][r][d][u]+h[cu][p]-h[cd-1][p]);
                    if((p = py-l-1) >= r+1) f[l+1][r][d][u] = max(f[l+1][r][d][u], f[l][r][d][u]+h[cu][p]-h[cd-1][p]);
                    if((p = px+u+1) <= n-d) f[l][r][d][u+1] = max(f[l][r][d][u+1], f[l][r][d][u]+g[p][cr]-g[p][cl-1]);
                    if((p = px-d-1) >= u+1) f[l][r][d+1][u] = max(f[l][r][d+1][u], f[l][r][d][u]+g[p][cr]-g[p][cl-1]);                 
                    ans = max(ans, f[l][r][d][u]);
                }
    printf("%d\n", ans);
    return 0;
}