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
const ll INF = 1LL<<59;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

#define N 5010
ll dp[N];

int main(){
	ll n;
	cin>>n;
	vector<ll> h(n), p(n);
	rep(i, n) cin>>h[i]>>p[i];
	vector<P> a(n);
	rep(i, n) a[i] = P(h[i]+p[i], i);
	sort(all(a));
	fill(dp+1, dp+n+1, INF);
	rep(i, n) for(int j = i; j >= 0; j--){
		ll x = h[a[i].snd], y = p[a[i].snd];
		if(dp[j]<=x) dp[j+1] = min(dp[j+1], dp[j]+y);
	}
	ll res = 0;
	rep(i, n+1) if(dp[i]<INF) res = i;
	cout<<res<<endl;
	return 0;
}
