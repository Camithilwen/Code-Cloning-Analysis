#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 2e3+5, M = 4e6+5, P = 1e9+7;
int n, m, f[N][N], fac[M], ifac[M], inv[M], ans;
int C(int n, int m) { return 1ll*fac[n]*ifac[n-m]%P*ifac[m]%P; }
int main()
{
    n = read(), m = read(); 
    inv[1] = ifac[0] = fac[0] = 1; 
    for(int i = 2; i <= n*m; ++i) inv[i] = 1ll*(P-P/i)*inv[P%i]%P;
    for(int i = 1; i <= n*m; ++i) fac[i] = 1ll*i*fac[i-1]%P, ifac[i] = 1ll*inv[i]*ifac[i-1]%P;
    f[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= i; ++j)
        {
            f[i][j] = f[i-1][j];
            if(j) f[i][j] = (f[i][j]+1ll*f[i][j-1]*(n-j+1)%P*C(n*m-i-(j-1)*(m-1)-1, m-2)%P)%P;
        }
    printf("%d\n", m == 1?1:f[n][n]);
    return 0;
}