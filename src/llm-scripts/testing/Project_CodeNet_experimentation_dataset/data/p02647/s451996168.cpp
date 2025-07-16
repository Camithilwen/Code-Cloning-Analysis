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
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	ll n,k; cin>>n>>k;
	vl a(n);
	rep(i,0,n) cin>>a[i];
	rep(q,0,k){
		vl b(n+1);
		rep(i,0,n){
			ll s=max((ll)0,(i-a[i]));
			ll t=min(i+a[i]+1,n);
			b[s]++; b[t]--;
		}
		rep(i,1,n+1) b[i]+=b[i-1];
		b.pop_back();
		if(a==b) break;
		a=b;
	}
	rep(i,0,n) cout<<a[i]<<" ";
	
	return 0;
}