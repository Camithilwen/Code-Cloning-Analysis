#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <bitset>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<' ';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



const int N = 2010, M = 4e6+10;
int n, k, dp[N][N];
int fac[M], ifac[M];
int C(int n, int m) {
	if (n<m) return 0;
	return (ll)fac[n]*ifac[m]%P*ifac[n-m]%P;
}
int main() {
	fac[0]=1;
	REP(i,1,M-1) fac[i]=(ll)fac[i-1]*i%P;
	ifac[M-1]=inv(fac[M-1]);
	PER(i,0,M-2) ifac[i]=(ll)ifac[i+1]*(i+1)%P;
	scanf("%d%d", &n, &k);
	if (k==1) return puts("1"),0;
	dp[0][0] = 1;
	REP(i,0,n) REP(j,0,i) {
		dp[i+1][j] = (dp[i+1][j]+dp[i][j])%P;
		dp[i][j+1] = (dp[i][j+1]+(ll)C(n*k-j*(k-1)-i-1,k-2)*dp[i][j])%P;
	}
	int ans = (ll)dp[n][n]*fac[n]%P;
	printf("%d\n", ans);
}






