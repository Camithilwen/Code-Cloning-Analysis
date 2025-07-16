#include <fstream>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<int,int>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, a;
lli dp [200000][2]; // best with i picked. 0: floor((i+1)/2); 1: ceil((i+1)/2)
// transition cands: i-2, i-3

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    lli ans = -__LONG_LONG_MAX__;
    cin >> a;
    dp[0][0] = 0; dp[0][1] = a;
    if (N <= 3) ans = max(ans, (lli) a);
    cin >> a;
    dp[1][0] = a; dp[1][1] = a;
    if (N <= 3) ans = max(ans, (lli) a);

    FOR(i,2,N) {
        cin >> a;
        dp[i][0] = dp[i-2][0];
        dp[i][1] = dp[i-2][1];
        // skip 2 cells
        if (i-3 >= 0) {
            if ((i+1)&1 == 0) dp[i][1] = max(dp[i][1], dp[i-3][1]);
            dp[i][0] = max(dp[i][0], dp[i-3][1]);
        }
        // skip 3 cells
        if (i-4 >= 0 && (i-2)/2 + 1 == (i+1)/2) dp[i][0] = max(dp[i][0], dp[i-4][1]);
        dp[i][0] += a;
        dp[i][1] += a;
        if (i&1) {
            lli mx = max(dp[i][0], dp[i][1]);
            dp[i][0] = mx;
            dp[i][1] = mx;
        }
        // cout << i+1 << '\n';
        // cout << dp[i][0] << "   " << dp[i][1] << '\n';
        if ((i+1)/2 == N/2) ans = max(ans, dp[i][0]);
        if ((i+2)/2 == N/2) ans = max(ans, dp[i][1]);
    }
    cout << ans << '\n';
}