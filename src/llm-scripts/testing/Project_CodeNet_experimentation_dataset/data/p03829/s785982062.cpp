#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 1; i < n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){

 	ll n, a, b;
 	cin >> n >> a >> b;
 	V<ll> x(n);
 	rep(i,n) cin >> x[i];

 	V<ll> dist(n-1);
 	rep(i,n) {
 		dist[i] = x[i+1] - x[i];
 		dist[i] *= a;
 	}

 	sort(all(dist));
 	int idx = 0;
 	ll ans = 0;
 	while(dist[idx] < b && idx < n-1) {
 		ans += dist[idx];
 		idx++;
 	}

 	ans += 1LL * (n-1 - idx) * b;
 	cout << ans << endl;
}