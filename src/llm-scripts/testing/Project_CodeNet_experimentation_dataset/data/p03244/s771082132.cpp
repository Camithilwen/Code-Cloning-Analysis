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
	ll n; cin>>n;
	map<ll,ll> a,b;
	rep(i,1,n+1){
		ll m; cin>>m;
		if(i%2==0){//偶数
			a[m]++;
		}
		else{
			b[m]++;
		}
	}
	vector<pair<ll,ll>> q(n),p(n);
	// q=even p=odd
	for(auto c:a) q.push_back(make_pair(c.second,c.first));
	for(auto c:b) p.push_back(make_pair(c.second,c.first));
	sort(all(p)); reverse(all(p));
	sort(all(q)); reverse(all(q));
	ll x,y;
	ll ans=n;
	rep(i,0,q.size()){
		if(i==2)break;
		rep(j,0,p.size()){
			if(j==2)break;
			if(q[i].second!=p[j].second){
				chmin(ans,n-q[i].first-p[j].first);
			}
		}
	}
	if(ans==n)ans/=2;
	cout<<ans<<endl;
	
	
	
	return 0;
}