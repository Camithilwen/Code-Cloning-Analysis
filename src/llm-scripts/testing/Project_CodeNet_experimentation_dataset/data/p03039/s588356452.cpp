#include "bits/stdc++.h"
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, a, b) for(int i=(b-1);i>=(a);i--)
#define REP(i, n) for(int i=0; i<(n); i++)
#define RREP(i, n) for(int i=(n-1); i>=0; i--)
#define REP1(i, n) for(int i=1; i<=(n); i++)
#define RREP1(i, n) for(int i=(n); i>=1; i--)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE_SORT(l) sort(ALL(l)); l.erase(unique(ALL(l)), l.end());
#define CONTAIN(a, b) find(ALL(a), (b)) != (a).end()
#define out(...) printf(__VA_ARGS__)

int dxy[] = {0, 1, 0, -1, 0};

void solve();
signed main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

/*================================*/
#if DEBUG
#define SIZE 100
#else
#define SIZE 123450
#endif

int N,M,K;

const int MAX = 5e5;
const int MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if (!fac[n]) COMinit();
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve() {
    cin>>N>>M>>K;
 
    int ans = 0;
    REP1(d, N-1) {
        int add = d*(N-d) % MOD;
        (add *= M*M)%=MOD;
        (ans += add)%=MOD;
    }
    REP1(d, M-1) {
        int add = d*(M-d) % MOD;
        (add *= N*N)%=MOD;
        (ans += add)%=MOD;
    }
    (ans *= COM(N*M-2,K-2))%=MOD;
    cout << ans << endl;
}