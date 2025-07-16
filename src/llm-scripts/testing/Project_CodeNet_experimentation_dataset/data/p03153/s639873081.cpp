#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<typename T>
void chk_min(T &a,T b){ if(a>b) a=b;}

ll a[MAXN];

int main(void)
{
	int n;	
	ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	ll ans=0;
	for(int i=1; i<=n; ++i) ans += a[i];
	
	for(int i=2; i<=n; ++i) chk_min(a[i], a[i-1]+d);
	for(int i=n-1; i>=1; --i) chk_min(a[i], a[i+1]+d);
	
	for(int i=1; i<=n; ++i) ans += a[i];
	printf("%lld",ans + d*(n-1) - a[1] - a[n]);
	return 0;
}