#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main()
{
	scanf("%d%d",&n,&m);
	if (m==1)
	{
		if (n==1)
		{
			printf("1\n1\n1\n");
		}
		else
		{
			printf("%d\n2\n1 %d\n",n,n-1);
		}
		return 0;
	}
	int t1=0,t2=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]&1)
		{
			if (!t1)
			{
				t1=i;
			}
			else if (!t2)
			{
				t2=i;
			}
			else
			{
				puts("Impossible");
				return 0;
			}
		}
	}
	if (t1)
	{
		swap(a[1],a[t1]);
	}
	if (t2)
	{
		swap(a[m],a[t2]);
	}
	for (int i=1;i<=m;i++)
	{
		printf("%d ",a[i]);
	}
	puts("");
	if (a[1]==1)
	{
		printf("%d\n",m-1);
	}
	else
	{
		printf("%d\n%d ",m,a[1]-1);
	}
	for (int i=2;i<m;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a[m]+1);
	return 0;
}
