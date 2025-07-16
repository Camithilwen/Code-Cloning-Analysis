#include<bits/stdc++.h>
int n,m,a[101],c[101],b[201],e,sum,now;
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("%d\n",n);
		if(n==1)puts("1"),puts("1");
		else puts("2"),printf("%d %d\n",n-1,1);
		return 0;
	}
	for(int i=1;i<=m;++i)
		scanf("%d",&a[i]),sum+=a[i],now+=a[i]/2;
	now+=sum/2;
	if(now<sum-1)puts("Impossible");
	else 
	{
		for(int i=1;i<=m;++i)
			if(a[i]&1)
			{
				if(c[1])c[m]=a[i];
				else c[1]=a[i];	
				a[i]=0;
			}
		for(int i=1,j=c[1]?1:0;i<=m;++i)
			if(a[i])
				c[++j]=a[i];
		for(int i=1;i<=m;++i)
			b[i]=c[i];
		++b[1];
		e=m;
		--b[m];
		if(c[m]==1)--e;
		for(int i=1;i<=m;++i)
			printf("%d ",c[i]);
		puts("");
		printf("%d\n",e);
		for(int i=1;i<=e;++i)
			printf("%d ",b[i]);
		puts("");
	}
}