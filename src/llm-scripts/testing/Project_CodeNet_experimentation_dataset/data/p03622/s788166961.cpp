#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
template <class T>
inline void _read(T &x)
{
    x = 0;
    char t = getchar();
    while (!isdigit(t)) t = getchar();
    while (isdigit(t))
    {
        x = x * 10 + t - '0';
        t = getchar();
    }
}
constexpr int MAXN = 1e6 + 10, mo = 998244353;
int n, m, ans, sum, fac[MAXN], inv[MAXN];
inline int C(int n, int m)
{
    return 1ll * fac[n] * inv[m] % mo * inv[n - m] % mo;
}
int main()
{
    _read(n), _read(m);
    if (n < m)
        swap(n, m);
    ans = n;
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n + m; ++i)
        fac[i] = 1ll * fac[i - 1] * i % mo, inv[i] = 1ll * (mo - mo / i) * inv[mo % i] % mo;
    for (int i = 2; i <= n + m; ++i)
        inv[i] = 1ll * inv[i] * inv[i - 1] % mo;
    for (int i = 1; i <= m; ++i)
        sum = (1ll * C(i << 1, i) * C(n + m - (i << 1), n - i) + sum) % mo;
    printf("%d", (1ll * sum * inv[2] % mo * inv[n + m] % mo * fac[n] % mo * fac[m] + ans) % mo);
    return 0;
}