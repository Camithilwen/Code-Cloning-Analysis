#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 200010
ll n, q, c, x[N];
set<P> dp[2];

int main(){
	cin>>n>>q>>x[0]>>c;
	rep(i, q) cin>>x[i+1];
	dp[0].insert(P(c, 0));
	for(int i = 1; i <= q; i++){
		int t = i%2;
		dp[t].clear();
		for(auto p: dp[!t]){
			dp[t].insert(P(x[i-1], p.snd+abs(x[i]-p.fst)));
			dp[t].insert(P(p.fst, p.snd+abs(x[i]-x[i-1])));
		}
		{
			auto it = dp[t].begin(), it2 = it; ++it2;
			while(it2!=dp[t].end()){
				while(it2!=dp[t].end() && it->snd+abs(it->fst-it2->fst)<=it2->snd){
					dp[t].erase(it2);
					it2 = it;
					++it2;
				}
				++it;
				if(it2!=dp[t].end()) ++it2;
			}
		}
		{
			auto it = dp[t].end();
			if(it!=dp[t].begin()) --it;
			auto it2 = it;
			if(it!=dp[t].begin()) --it2;
			while(it!=dp[t].begin()){
				while(it!=dp[t].begin() && it->snd+abs(it->fst-it2->fst)<=it2->snd){
					dp[t].erase(it2);
					it2 = it;
					if(it2!=dp[t].begin()) --it2;
				}
				if(it!=dp[t].begin()){
					--it;
					if(it2!=dp[t].begin()) --it2;
				}
			}
		}
	}
	ll res = 1e17;
	for(auto p: dp[q%2]) res = min(res, p.snd);
	cout<<res<<endl;
	return 0;
}
