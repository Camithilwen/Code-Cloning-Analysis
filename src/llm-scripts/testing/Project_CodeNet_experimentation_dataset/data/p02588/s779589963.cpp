#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> bool readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
	return c=='.';
}
const int MAXN=200005;

int n;
ll a[MAXN];
pii b[MAXN];
int cnt[100][100];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	int s=0;
	for(int i=1;i<=n;++i)
	{
		ldb d;
		scanf("%Lf",&d);
		a[i]=d*1000000000+0.5;
		while(a[i]%2==0)a[i]>>=1,++b[i].x;
		while(a[i]%5==0)a[i]/=5,++b[i].y;
		++cnt[b[i].x][b[i].y];
		if(b[i].x>=9 && b[i].y>=9)++s;
	}
	sort(b+1,b+n+1);
	ll ans=0;
	for(int i=0;i<=55;++i)
		for(int j=0;j<=55;++j)
			for(int x=0;x<=55;++x)
				for(int y=0;y<=55;++y)
					if(i+x>=18 && j+y>=18)
						ans+=1ll*cnt[i][j]*cnt[x][y];
	printf("%lld\n",(ans-s)/2);
	return 0;
}