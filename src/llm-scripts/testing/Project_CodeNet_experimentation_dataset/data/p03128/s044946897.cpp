#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n, m; cin >> n >> m;
    vint change = {0,2,5,5,4,5,6,3,7,6};
    vint a(m);
    rep(i,m) cin >> a[i];
    set<int> st;
    rep(i,m) st.insert(change[a[i]]);
    vint dp(n+1,-1);    
    dp[0] = 0;
    REP(i,n+1) {
        for (auto x : st) {
            if (i-x >= 0 && dp[i-x] != -1) {
                chmax(dp[i],dp[i-x]+1);
            }
        }
    }
    int n_split = dp[n];
    sort(rall(a));
    string ans;
    while (n_split--) {
        rep(i,m) {
            if (n-change[a[i]] < 0) continue;
            if (dp[n-change[a[i]]] == dp[n] - 1) {
                ans += to_string(a[i]);
                n -= change[a[i]];
                break;
            }
        }
    }
    cout << ans << endl;
}