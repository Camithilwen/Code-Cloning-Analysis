// Date: 2020-03-19

#include <algorithm>
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
#define D(x) cout<<#x<<" = "<<x<<endl;
#define SZ(x) ((int)x.size())
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int r[N][30], x[N], n, L, Q, dep;

void init() {
    rep(i, 1, n) r[i][0] = upper_bound(x+i, x+n+1, x[i]+L)-x-1;
    rep(d, 1, 20) {
        rep(i, 1, n) {
            r[i][d] = r[r[i][d-1]][d-1];
        }
    }
}

int main() {
    FIO;
    cin >> n;
    rep(i, 1, n) cin >> x[i];
    cin >> L >> Q;
    init();
    while(Q--) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        int ans = 0;
        for(int i = 20; i >= 0; --i) {
            if(r[u][i] < v) {
                ans += (1 << i);
                u = r[u][i];
            }
        }
        cout << ans+1 << '\n';
    }

    return 0;
}