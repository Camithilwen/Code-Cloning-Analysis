#include<stdio.h>
int main()
{
	int a[11][11],n,i,j;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;++i)
		{
			a[i][n] = 0;
			for(j=0;j<n;++j)
			{
				scanf("%d", &a[i][j]);
				a[i][n] += a[i][j];
			}
		}
		for(j = 0; j <= n; ++j)
		{
			a[n][j] = 0;
			for(i = 0; i < n; ++i)
				a[n][j] += a[i][j];
		}
		for(i = 0; i <= n; ++i)
		{
			for(j = 0; j <= n; ++j)
			{
				printf("%5d",a[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}