/*
 * Author: ylx
 * Lang: c++
 * Prog: agc002F
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x, int y)
{
    if (x < y)
        x = y;
}
void qmin(int &x, int y)
{
    if (x > y)
        x = y;
}
inline ll read()
{
    char s;
    ll k = 0, base = 1;
    while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
        ;
    if (s == EOF)
        exit(0);
    if (s == '-')
        base = -1, s = getchar();
    while (isdigit(s))
        k = k * 10 + (s ^ '0'), s = getchar();
    return k * base;
}
inline void write(ll x)
{
    static char cnt, num[20];
    cnt = 0;
    if (!x)
    {
        putchar('0');
        return;
    }
    for (; x; x /= 10)
        num[++cnt] = x % 10;
    for (; cnt; putchar(num[cnt--] + 48))
        ;
}
const int maxn = 4e6 + 100;
const ll mod = 1e9 + 7;
int jie[maxn], ny[maxn];
int n, m;
ll ksm(ll x, int y)
{
    ll sum = 1;
    while (y)
    {
        if (y & 1)
            sum = sum * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return sum;
}
void init()
{
    n = 4e6;
    jie[0] = 1;
    for (int i = 1; i <= n; i++)
        jie[i] = (ll)jie[i - 1] * i % mod;
    ny[n] = ksm(jie[n], mod - 2);
    for (int i = n; i >= 1; i--)
        ny[i - 1] = (ll)ny[i] * i % mod;
}
ll C(int x, int y)
{
    if (x < y)
        return 0;
    return (ll)jie[x] * ny[x - y] % mod * ny[y] % mod;
}
ll f[2][2030];
int main()
{
#ifdef ylx
    freopen("agc002F.in", "r", stdin);
    freopen("agc002F.out", "w", stdout);
#endif
    init();
    n = read(), m = read();
    if (m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    f[0][0] = 1;
    for (int i = 1, p; i <= n; i++)
    {
        p = i & 1;
        memset(f[p], 0, sizeof(f[p]));
        for (int j = 0; j <= i; j++)
        {
            if (!j)
            {
                f[p][j] = f[p ^ 1][j];
                continue;
            }
            f[p][j] = f[p ^ 1][j] + f[p][j - 1] * (n - j + 1) % mod * C((n - j + 1) * (m - 1) + n - i - 1, m - 2) % mod;
        }
    }
    write(f[n & 1][n]);
}