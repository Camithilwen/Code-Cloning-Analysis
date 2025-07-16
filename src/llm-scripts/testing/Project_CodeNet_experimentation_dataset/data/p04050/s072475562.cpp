#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[100005];
int main()
{
	scanf("%d%d",&n,&m);
	int ct=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2) ct++;
	}
	if(ct>2)
	{
		printf("Impossible\n");
		return 0;
	}
	int id1=0,id2=0;
	for(int i=1;i<=m;i++)
		if(a[i]%2)
		{
			if(!id1) id1=i;
			else if(!id2) id2=i;
		}
	if(id1)
	{
		if(id2==1) id2=id1;
		swap(a[1],a[id1]);
	}
	if(id2) swap(a[m],a[id2]);
	if(m==1)
	{
		if(a[1]==1) printf("1\n1\n1\n");
		else printf("%d\n2\n%d 1\n",a[1],a[1]-1);
		return 0;
	}
	if(!id2)
	{
		for(int i=1;i<=m;i++)
			printf("%d ",a[i]);
		printf("\n%d\n",m);
		for(int i=1;i<=m;i++)
		{
			if(i==1) printf("%d ",a[i]+1);
			else if(i==m) printf("%d ",a[i]-1);
			else printf("%d ",a[i]);
		}
		return 0;
	}
	if(n==2&&m==2)
	{
		printf("1 1\n1\n2\n");
		return 0;
	}
	if(n==4&&m==3)
	{
		printf("1 2 1\n2\n2 2\n");
		return 0;
	}
	if(a[1]==1&&a[m]==1)
	{
		for(int i=1;i<=m;i++)
			printf("%d ",a[i]);
		printf("\n%d\n",m-1);
		for(int i=2;i<=m;i++)
		{
			if(i==m) printf("%d ",a[i]+1);
			else printf("%d ",a[i]);
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",a[i]);
	printf("\n%d\n",m);
	for(int i=1;i<=m;i++)
	{
		if(i==1) printf("%d ",a[i]+1);
		else if(i==m) printf("%d ",a[i]-1);
		else printf("%d ",a[i]);
	}
	return 0;
}