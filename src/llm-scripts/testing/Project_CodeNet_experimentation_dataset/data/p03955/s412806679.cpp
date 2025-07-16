#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,a[5][N],i,j,k,x,y,b[N],c[2];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=3;++i)
		for(j=1;j<=n;++j)
			scanf("%d",a[i]+j);
	for(i=1;i<=n;++i)
	{
		x=y=a[1][i];
		for(j=2;j<=3;++j)
			x=max(x,a[j][i]),y=min(y,a[j][i]);
		if(x-y!=2||y+1!=a[2][i])
		{
			printf("No");
			return 0;
		}
		b[i]=x/3;
		if(a[1][i]!=y)
			c[i&1]=!c[i&1];
		if((x/3-i)%2)
		{
			printf("No");
			return 0;
		}
	}
	for(i=1;i<=n;++i)
	while(i!=b[i])
	{
		swap(b[i],b[b[i]]);
		c[i&1^1]=!c[i&1^1];
	}
	if(c[0]||c[1])
		printf("No");
	else
		printf("Yes");
	return 0;
}
