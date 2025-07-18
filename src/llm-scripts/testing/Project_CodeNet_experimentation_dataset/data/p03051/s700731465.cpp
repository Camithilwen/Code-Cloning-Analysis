#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    Rep(i, n) data[i] ^= data[i-1];

    vi dp0(1 << 20, 1), dp1(1 << 20, 0), zeros(1 << 20, 0);
    // 始点に 0 があると考えるので全ての x について初期0数1個
    int zero = 0; 
    rep(i, n) {
        if (!data[i]) {
            zero++;
        } else {
            (dp0[data[i]] += dp1[data[i]] * (zero - zeros[data[i]])) %= MOD; // 0 の累積を求める
            (dp1[data[i]] += dp0[data[i]]) %= MOD; // i 番目の解が求められ、区間の値 k = data[i] の時の解の累積が増える
            zeros[data[i]] = zero;
            //std::cout << dp0[data[i]] << " , " << dp1[data[i]] << std::endl;
        }
    }

    if (data.back()) {
        std::cout << dp0[data.back()] << std::endl;
    } else {
        int ans = 1;
        rep(i, zero-1) ans = (ans * 2) % MOD;
        rep(i, dp1.size()) ans += dp1[i];
        std::cout << ans % MOD << std::endl;
    }

    return 0;
}
