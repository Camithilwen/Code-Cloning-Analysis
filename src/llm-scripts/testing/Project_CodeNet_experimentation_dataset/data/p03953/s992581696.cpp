#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

void print(ll x){
    cout << x << ".00000000000000" << endl;
}

int main(){
    int N;
    cin >> N;
    ll x[N];
    rep(i, N) cin >> x[i];
    ll d[N-1];
    rep(i, N-1) d[i] = x[i+1]-x[i];
    int M; ll K;
    cin >> M >> K;
    int dp[60][N-1];
    rep(i, N-1) dp[0][i] = i;
    rep(i, M){
        int a;
        cin >> a;
        swap(dp[0][a-2], dp[0][a-1]);
    }
    rep2(i, 1, 59){
        rep(j, N-1) dp[i][j] = dp[i-1][dp[i-1][j]];
    }
    ll ans = x[0];
    print(ans);
    rep(i, N-1){
        int now = i;
        rep(j, 60){
            if(K&(1LL<<j)) now = dp[j][now];
        }
        print(ans += d[now]);
    }
}