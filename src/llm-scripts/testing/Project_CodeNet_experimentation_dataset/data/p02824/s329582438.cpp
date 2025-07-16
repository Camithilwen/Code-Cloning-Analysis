#include<cstdio>
#include<algorithm>
#define RI register int
#define CI const int&
using namespace std;
const int N=100005;
int n,a[N],m,v,p; long long sum[N];
inline bool cmp(CI x,CI y)
{
	return x>y;
}
int main()
{
	RI i; for (scanf("%d%d%d%d",&n,&m,&v,&p),i=1;i<=n;++i) scanf("%d",&a[i]);
	for (sort(a+1,a+n+1,cmp),i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for (i=p+1;i<=n;++i)
	{
		int dlt=max(0,v-(p+n-i)); long long tot=sum[i-1]-sum[p-1];
		if (a[i]+m<a[p]||1LL*(i-p)*(a[i]+m)+1-tot<=1LL*dlt*m) return printf("%d",i-1),0;
	}
	return printf("%d",n),0;
}