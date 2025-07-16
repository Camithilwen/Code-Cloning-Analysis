#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

ll sol_even(int n, const vector<ll> &a) {
    ll dp[200200][2];
    rep(i,200200) rep(j,2) dp[i][j] = -LINF;
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    rep(i,n) {
        if (i+2 < n) chmax(dp[i+2][0], dp[i][0]+a[i+2]);
        if (i+3 < n) chmax(dp[i+3][1], dp[i][0]+a[i+3]);
        if (i+2 < n) chmax(dp[i+2][1], dp[i][1]+a[i+2]);
    }

    return max(dp[n-2][0], dp[n-1][1]);
}

ll dp[200200][3][2];
ll sol_odd(int n, const vector<ll> &a) {
    rep(i,200200) rep(j,3) rep(k,2) dp[i][j][k] = -LINF;
    dp[0][0][0] = a[0];
    dp[1][1][0] = a[1];
    dp[2][2][0] = a[2];
    rep(i,n) {
        if (i+2 < n && i+2 != n-1) chmax(dp[i+2][0][0], dp[i][0][0]+a[i+2]);
        if (i+3 < n) chmax(dp[i+3][1][0], dp[i][0][0]+a[i+3]);
        if (i+4 < n) chmax(dp[i+4][0][1], dp[i][0][0]+a[i+4]);
        if (i+3 < n) chmax(dp[i+3][2][0], dp[i][1][0]+a[i+3]);
        if (i+2 < n) chmax(dp[i+2][1][0], dp[i][1][0]+a[i+2]);
        if (i+2 < n) chmax(dp[i+2][2][0], dp[i][2][0]+a[i+2]);
        if (i+2 < n) chmax(dp[i+2][0][1], dp[i][0][1]+a[i+2]);
    }
    return max({dp[n-3][0][0], dp[n-2][1][0], dp[n-1][2][0], dp[n-1][0][1]});
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    if (n%2) cout << sol_odd(n,a) << '\n';
    else cout << sol_even(n,a) << '\n';

    return 0;
}