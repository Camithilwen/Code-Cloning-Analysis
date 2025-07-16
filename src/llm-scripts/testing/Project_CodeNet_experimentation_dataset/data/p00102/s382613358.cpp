#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	int i,j;
	for(;;)
	{
		cin >> n ;
		if(n==0)
			break;
		int table[12][12]={0};
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> table[i][j] ;
			}
		}
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(j!=n)
				{
					printf("%5d",table[i][j]);
					table[i][n]+=table[i][j];
					table[n][j]+=table[i][j];
				}
				else
					printf("%5d\n",table[i][j]);
			}
		}
	}
}