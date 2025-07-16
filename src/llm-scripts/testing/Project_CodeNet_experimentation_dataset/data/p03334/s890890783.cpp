#include <bits/stdc++.h>
using namespace std;
#define N 610
int a[N][N],n,d1,d2,b;
int main()
{
	scanf("%d%d%d",&n,&d1,&d2);
	while (d1%4==0)
	{
		b++;
		d1/=4;
	}
	if (d1&1)
	{
		for (int i=0; i<2*n; i++)
			for (int j=0; j<2*n; j++)
				if (((i>>b)+(j>>b))&1)
					a[i][j]=1;
	}
	else
		for (int i=0; i<2*n; i++)
			for (int j=0; j<2*n; j++)
				if ((i>>b)&1) a[i][j]=1;
	b=0;
	while (d2%4==0)
	{
		b++;
		d2/=4;
	}
	if (d2&1)
		for (int i=0; i<2*n; i++)
		{
			for (int j=0; j<2*n; j++)
				if (((i>>b)+(j>>b))&1)
					a[i][j]=1;
		}
	else
		for (int i=0; i<2*n; i++)
			for (int j=0; j<2*n; j++)
				if ((i>>b)&1) a[i][j]=1;

	int tt=0;
	for (int i=0; i<2*n; i++)
		for (int j=0; j<2*n; j++)
			if (a[i][j]==0)
			{
				tt++;
				printf("%d %d\n",i,j);
				if (tt==n*n) return 0;
			}
	return 0;
}