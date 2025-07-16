#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    ll n = sz(s);
    reverse(rng(s));
    s.push_back('0');
    vvl dp(n + 2, vl(2, LINF));
    dp[0][0] = 0, dp[0][1] = 0;
    rep(i, n + 1) rep(j, 2) rep(k, 2) {     // j:繰り上がりをする k:繰り上がりされた
        ll c = s[i] - '0';
        if (i > 0 && k) c++;
        if (c == 10 && j == 0) continue;
        if (c == 0 && j == 1) continue;
        if (j) chmin(dp[i + 1][j], dp[i][k] + (10 - c) % 10);
        else chmin(dp[i + 1][j], dp[i][k] + c);
    }
    cout<<min(dp[n + 1][0], dp[n + 1][1])<<endl;
}