#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,A,B,C,D;
ll d[1001][1001];
ll fac[1001],inv[1001];
ll go(int N,int K)
{
	if(N==0)return fac[n];
	if(K>B)return 0;
	ll &ret=d[N][K];
	if(ret!=-1)return ret;
	ret=go(N,K+1);
	for(int i=C;i<=D && i*K<=N;i++)
	{
		ll tt=POW(inv[K],i);
		ll t=(tt*inv[i])%MOD;
		ret=(ret+t*go(N-i*K,K+1))%MOD;
	}
	return ret;
}
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 1000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[1000] = POW(fac[1000], MOD - 2);
	fdn(i, 999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	MEM_1(d);
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	printf("%lld",go(n,A));
}