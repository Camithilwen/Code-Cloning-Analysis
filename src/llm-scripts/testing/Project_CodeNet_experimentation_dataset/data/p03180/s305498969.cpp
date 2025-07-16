#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a-1)
#define trav(x, a) for (auto& x: a)

const int MX  = 2e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);

ll arr[18][18],dp[1<<18],cost[1<<18];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    F0R(i,N) F0R(j,N) {
        cin >> arr[i][j];
    }

    memset(dp,-1,sizeof dp);
    F0R(i,N) dp[i] = 0;

    F0R(mask,1<<N) {
        F0R(i,N) {
            FOR(j,i+1,N) {
                if (mask&(1<<i) && mask&(1<<j)) {
                    cost[mask] += arr[i][j];
                }
            }
        }
    }

    F0R(mask,1<<N) {
        for (int smask = mask; smask; smask = (smask-1)&mask) {
            dp[mask] = max(dp[mask],dp[mask^smask]+cost[smask]);
        }
    }

    cout << dp[(1<<N)-1] << "\n";

}
