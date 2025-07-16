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
#define INF 1987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[2000][2002];
int v[2002][2002],ex[2002][2002],ey[2002][2002];
int main() {
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
		v[i+1][j+1]=v[i][j+1]+v[i+1][j]-v[i][j]+(s[i][j]=='1');
	fup(i,0,n-2,1)
		fup(j,0,m-1,1)
		ex[i+1][j+1]=ex[i][j+1]+ex[i+1][j]-ex[i][j]+(s[i][j]=='1' && s[i+1][j]=='1');
	fup(i,0,n-1,1)
		fup(j,0,m-2,1)
		ey[i+1][j+1]=ey[i][j+1]+ey[i+1][j]-ey[i][j]+(s[i][j]=='1' && s[i][j+1]=='1');
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int t1=v[x2][y2]-v[x2][y1-1]-v[x1-1][y2]+v[x1-1][y1-1];
		int t2=ex[x2-1][y2]-ex[x2-1][y1-1]-ex[x1-1][y2]+ex[x1-1][y1-1];
		int t3=ey[x2][y2-1]-ey[x2][y1-1]-ey[x1-1][y2-1]+ey[x1-1][y1-1];
		printf("%d\n",t1-t2-t3);
	}
}