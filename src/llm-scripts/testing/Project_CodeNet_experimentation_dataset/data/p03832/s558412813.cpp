/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) {bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48; if (b)x=-x;}
template <typename T> inline void wrip(T x) {if (x > 9) wrip(x / 10); putchar(x%10 + 48); }

template <typename T> inline void write(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar(' ');}
template <typename T> inline void writeln(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar('\n');}
inline char readch() {char c; do c = getchar(); while (c == '\n' || c == ' '); return c;}
inline void reads(string &s) {char c; while((c=getchar())==' '||c =='\n'); s=c; while((c=getchar())!=' '&&c!='\n') s+=c;}
inline void getlines(string &s) {char c; while((c=getchar())=='\n'); s=c; while((c=getchar())!='\n') s+=c;}
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;

const ld pi = acos(-1);
const ll inf = 1e9,
mod = 1e9 + 7,
N = 1011;

int n, a, b, c, d;
ll f[N][N], cb[N][N], g[N][N];
ll fac[N], inv[N];
void Inc(ll &a, ll b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
ll pw(ll a, ll b) {
    if (b == 0)
        return 1;
    ll t = pw(a, b / 2);
    t = t * t % mod;
    if (b % 2)
        return t * a % mod;
    return t;
}
int res, dx[111], pa[111];
void Try(int x) {
    if (x > n) {
        int cnt[21], num[21];
        memset(cnt, 0, sizeof(cnt));
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; i++)
            cnt[pa[i]]++;
        for (int i = 1; i <= n; i++) {
            if (!cnt[i])
                continue;
            if (cnt[i] < a || cnt[i] > b)
                return;
            num[cnt[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!num[i])
                continue;
            if (num[i] > d || num[i] < c)
                return;
        }
        res++;
        return;
    }
    for (int i = 1; i <= x; i++) {
        if (dx[i])
            continue;
        dx[x] = i != x;
        pa[x] = i;
        Try(x + 1);
        dx[x] = 0;
    }
}
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(n);
    read(a);
    read(b);
    read(c);
    read(d);
//    Try(1);
//    cout << res << '\n';
    cb[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            cb[i][j] = (cb[i - 1][j] + cb[i - 1][j - 1]) % mod;
    }
    g[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        g[i][0] = 1;
        for (int j = i; j <= n; j += i)
            g[i][j] = (ll) cb[j][j / i] * g[i - 1][j - j / i] % mod;
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (ll)fac[i - 1] * i % mod;
    inv[n] = pw(fac[n], mod - 2);
    for (int i = n; i >= 1; i--)
        inv[i - 1] = (ll)inv[i] * i % mod;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            g[i][j] = (ll)g[i][j] * inv[i] % mod;
    f[a - 1][0] = 1;
    for (int i = a; i <= b; i++) {
        int lim = min(d * i, n);
        int im = i - 1;
        for (int j = i * c, grs = c; j <= lim; j += i, grs++)
            for (int k = j, rem = n, kk = k - j; k <= n; k++, rem--, kk++) {
                ll tmp = f[im][kk];
                tmp = tmp * cb[rem][j] % mod;
                tmp = tmp * g[grs][j] % mod;
                Inc(f[i][k], tmp);
            }
        for (int j = 0; j <= n; j++)
            Inc(f[i][j], f[im][j]);
    }
    cout << f[b][n];
}
