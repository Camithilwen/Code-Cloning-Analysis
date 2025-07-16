#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

signed main(){
	ll n,m; cin>>n>>m;
	vl a(m);
	vector<char> b(m);
	ll ans=-1;
	rep(i,0,m){
		cin>>a[i]>>b[i];
	}
	rep(i,0,1000){
		string s=to_string(i);
		if(s.size()!=n)continue;
		bool ok=true;
		rep(i,0,m){
			if(s[a[i]-1]!=b[i])ok=0;
		}
		if(ok){
			ans=i;
			break;
		}
	}
	cout << ans << endl;

	return 0;
}