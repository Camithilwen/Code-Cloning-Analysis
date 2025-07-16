// Date: 2020-02-29

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n, m, a, b;
LL fac[N], inv[N];

void add(LL& x, LL y) { x = (x + y) % mod; }

void init() {
    fac[0] = inv[0] = 1;
    rep(i, 1, N-1) fac[i] = fac[i-1] * i % mod, inv[i] = qpow(fac[i], mod-2, mod);
}

LL C(int x, int y) {
    return fac[x] * inv[y] % mod * inv[x-y] % mod;
}

LL cal(int x1, int y1, int x2, int y2) {
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<< C(x2-x1+y2-y1, x2-x1) <<endl;
    return C(x2-x1+y2-y1, x2-x1);
}

int main() {
    init();
    scanf("%d%d%d%d", &n, &m, &a, &b);
    LL ans = 0;
    rep(i, 1, n-a) add(ans, cal(1, 1, i, b) * cal(i, b+1, n, m) % mod);
    printf("%lld\n", ans);

    return 0;
}