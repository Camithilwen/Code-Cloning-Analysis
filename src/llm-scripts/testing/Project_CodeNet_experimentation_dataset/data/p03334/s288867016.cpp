#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[605][605];

void work()
{
	int d,l=1;
	scanf("%d",&d);
	for(; d%4==0; d>>=2)
		l<<=1;
	if(~d&1)
	{
		for(int i=1; i<=n; i+=l)
			if(!(i/l&1))
				for(int k=i; k<=min(n,i+l-1); ++k)
					for(int j=1; j<=n; j++)
						a[k][j]++;
	}
	else if(d%4==1)
	{
		for(int i=1; i<=n; i+=l)
			for(int j=1; j<=n; j+=l)
				if((i/l&1)^(j/l&1)^1)
					for(int k=i; k<=min(n,i+l-1); ++k)
						for(int p=j; p<=min(n,j+l-1); ++p)
							a[k][p]++;
	}
	else
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				a[i][j]++;
	}
}

int main()
{
	scanf("%d",&n);
	n<<=1;
	work(); work();
/*	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			printf("%d ",a[i][j]);
		puts("");
	}*/
	for(int s=0,i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(a[i][j]==2)
			{
				++s;
				printf("%d %d\n",i-1,j-1);
				if(s*4==n*n)
					return 0;
			}
	return 0;
}