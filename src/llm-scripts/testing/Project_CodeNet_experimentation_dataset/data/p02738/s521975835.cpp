#include <cstdio>
#include <algorithm>
const int N = 6e3+5;
int n, P, f[N][N<<1], ans; void fix(int &x) { x<P?0:x-=P; }
int main()
{
    scanf("%d%d", &n, &P), n *= 3, f[0][N] = 1;
    for(int i = 0; i < n; ++i) for(int j = -i; j <= i; ++j)
        fix(f[i+1][j+1+N]+=f[i][j+N]), 
        fix(f[i+2][j-1+N]+=f[i][j+N]*(i+1ll)%P),
        fix(f[i+3][j+N]+=f[i][j+N]*(i+1ll)*(i+2ll)%P);
    for(int i = 0; i <= n; ++i) fix(ans+=f[n][i+N]); printf("%d\n", ans);
    return 0;
}