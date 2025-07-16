#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 3e2+5;
int n, m, f[N][N][N], ans; char s[N];
int main()
{
    scanf("%s", s+1), n = strlen(s+1), m = read();
    for(int i = 1; i <= n; ++i) f[0][i][i] = 1;
    for(int k = 0; k <= m; ++k)
        for(int l = 2; l <= n; ++l)
            for(int i = 1, j = l; j <= n; ++i, ++j)
            {
                f[k][i][j] = max(f[k][i+1][j], f[k][i][j-1]);
                if(s[i] == s[j]) f[k][i][j] = max(f[k][i][j], f[k][i+1][j-1]+2);
                if(k) f[k][i][j] = max(f[k][i][j], f[k-1][i+1][j-1]+2);
            }
    for(int i = 0; i <= m; ++i) ans = max(ans, f[i][1][n]);
    printf("%d\n", ans);
    return 0;
}