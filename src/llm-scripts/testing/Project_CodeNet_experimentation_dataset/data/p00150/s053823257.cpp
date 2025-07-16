#include<stdio.h>
int main()
{
	int i,j,n;
	const int N=10001;
	bool p[N];
	for(i=2;i<N;++i)p[i]=true;
	for(i=2;i<=N/2;++i)if(p[i])for(j=2*i;j<N;j+=i)p[j]=false;
	while(scanf("%d",&n),n){for(i=n;;--i)if(p[i]&&p[i-2])break;printf("%d %d\n",i-2,i);}
	return 0;
}