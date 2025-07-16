#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n;   cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    vector<ll> a(n);
    rep(i, n)   cin >> a[i];
    rep(i, n+1) rep(j, 2) dp[i][j] = -LINF;
    dp[0][0] = 0;
    rep(i, n){
        dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
        dp[i+1][1] = max(dp[i][1]+a[i], dp[i][0]-a[i]);
    }
    cout << dp[n][0] << endl;
}
