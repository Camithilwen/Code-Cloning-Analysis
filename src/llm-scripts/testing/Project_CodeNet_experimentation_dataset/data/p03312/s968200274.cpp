#include <cstdio>
#include <algorithm>
#define INF 2147483647
#define max_n 1000000
using namespace std;
int a[max_n+1];
long long psm[max_n+2],nsm[max_n+2];
long long calc(long long a,long long b,long long c,long long d){
	a>b&&(swap(a,b),1),c>d&&(swap(c,d),1);
	return max(b,d)-min(a,c);
}
template<typename T>void minify(T&x,const T&y){
	y<x&&(x=y);
}
int main(){
	int n,i;
	scanf("%d",&n),psm[0]=0;
	for(int i=0; ++i<=n; psm[i]=psm[i-1]+a[i])
		scanf("%d",a+i);
	nsm[n+1]=0;
	for(int i=n+1; --i; nsm[i]=nsm[i+1]+a[i]);
	long long x,y,ans=INF;
	for(int j=0,i=0,k=0; ++j<=n; minify(ans,calc(psm[i],psm[j]-psm[i],psm[k]-psm[j],psm[n]-psm[k]))){
		for(y=(x=psm[j])>>1; psm[++i]<=y; );
		y-psm[i-1]<psm[i]-y&&(--i);
		for(y=(x=nsm[j+1])>>1; nsm[++k+1]>y; );
		nsm[k]-y<=y-nsm[k+1]&&(--k);
//		printf("*(%d,%d,%d)\n",i,j,k);
	}
	printf("%lld\n",ans);
	return 0;
}