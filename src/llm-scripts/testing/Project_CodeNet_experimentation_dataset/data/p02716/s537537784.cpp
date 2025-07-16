#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " << #x << " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;


void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    ll ans = -LINF;
    if (n % 2 == 0) {
        ll sum = 0;
        for (int i = 1; i < n; i+=2) sum += A[i];
        chmax(ans, sum);
        for (int i = 0; i < n; i+=2){
            sum += A[i] - A[i + 1];
            chmax(ans, sum);
        }
        cout << ans << endl;
        return;
    } else {
        n /= 2;
        ll dp[n + 1][3];
        rep(i, n + 1) rep(j, 3) dp[i][j] = -LINF;
        dp[0][0] = dp[0][1] = dp[0][2] = 0LL;
        rep(i, n) {
            chmax(dp[i + 1][0], dp[i][0] + A[2 * i]);
            chmax(dp[i + 1][1], max(dp[i][0], dp[i][1]) + A[2 * i + 1]);
            chmax(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + A[2 * i + 2]);
        }
        cout << *max_element(dp[n], dp[n] + 3) << endl;
        return;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
