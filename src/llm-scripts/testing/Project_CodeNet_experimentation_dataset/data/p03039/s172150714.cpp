#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;

vector<ll> fac(MAX), finv(MAX), inv(MAX);

void comInit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i=2; i<MAX; i++){
		fac[i] = fac[i-1]*i % mod;
		inv[i] = mod - inv[mod%i] * (mod/i) % mod;
		finv[i] = finv[i-1] * inv[i] % mod;
	}
}


ll com(ll n, ll k){
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main(){
	ll n,m,k; cin >> n >> m >> k;
	comInit();
	ll sum = 0;
	REP(i,1,m){
		sum += n*n%mod*i%mod*(m-i)%mod;
		sum %= mod;
	}
	REP(i,1,n){
		sum += m*m%mod*i%mod*(n-i)%mod;
		sum %= mod;
	}
	cout << sum*com(n*m-2,k-2)%mod << endl;
}