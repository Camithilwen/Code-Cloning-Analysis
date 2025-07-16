#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
ll g[10][10];

signed main(){
	//cout << fixed << setprecision(10);
	int n; cin >> n;
    vl a(n);
    rep(i,0,n)cin >> a[i];
    ll m = MOD;
    ll ans = 0;
    rep(i,0,n){
        ans += (a[i] <= m);
        chmin(m,a[i]);
    }
    cout << ans << endl;
}

