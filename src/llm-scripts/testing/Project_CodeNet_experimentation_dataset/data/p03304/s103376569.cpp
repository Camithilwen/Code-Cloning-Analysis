#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 2e5 + 100;
const int maxN = 6e6;
const int oo = 1e18;
const int mod  = 1e9 + 7;


signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("spm.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);
    int n, m, d; cin >> n >> m >> d;
    double ans = (double) (m - 1.00) * 2.00 * (n - d) * 1.00 / (n * 1.00 * n);
    if(d == 0) ans /= 2.00;
    cout << fixed << setprecision(10) << ans;
}
