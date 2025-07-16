#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,s;
deque<pair<ll,ll> >vec;
ll rec(){
	if(vec.empty()) return 0LL;
	int sz = vec.size();
	if(vec[0].sc >= vec[sz-1].sc){
		vec[0].sc += vec[sz-1].sc;
		ll pos = vec[sz-1].fi;
		vec.pop_back();
		sz--;
		if(vec[0].fi > s){
			return pos-s;
		}
		else if(vec[sz-1].fi < s){
			return s-vec[0].fi-vec[0].fi+pos;
		}
		else{
			if(vec[0].sc >= vec[sz-1].sc){
				ll cst = pos-vec[sz-1].fi;
				ll ans = rec();
				return ans+cst;
			}
			else{
				ll cst = pos-vec[0].fi;
				ll ans = rec();
				return ans+cst;
			}
		}
	}
	else{
		vec[sz-1].sc += vec[0].sc;
		ll pos = vec[0].fi;
		vec.pop_front();
		sz--;
		if(vec[sz-1].fi < s){
			return s-pos;
		}
		else if(vec[0].fi > s){
			return vec[sz-1].fi-s-pos+vec[sz-1].fi;
		}
		else{
			if(vec[0].sc >= vec[sz-1].sc){
				ll cst = vec[sz-1].fi-pos;
				ll ans = rec();
				return ans+cst;
			}
			else{
				ll cst = vec[0].fi-pos;
				ll ans = rec();
				return ans+cst;
			}
		}
	}
}
int main(){
	cin>>n>>s;
	rep(i,n){
		int x,p ; cin>>x>>p;
		vec.pb(pair<ll,ll>(x,p));
	}
	if(vec[0].fi > s){
		cout<<vec[n-1].fi-s<<endl;
		return 0;
	}
	if(vec[n-1].fi < s){
		cout<<s-vec[0].fi<<endl;
		return 0;
	}
	ll ans = rec();
	cout<<ans<<endl;
}