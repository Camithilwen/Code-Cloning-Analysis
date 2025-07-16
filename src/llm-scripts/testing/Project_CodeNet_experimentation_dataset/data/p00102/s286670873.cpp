#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n) 
	{
		int f[n+1][n+1];
		memset(f,0,sizeof(f));
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				cin>>f[i][j];
				f[i][n]+=f[i][j];
				f[n][j]+=f[i][j];
				f[n][n]+=f[i][j];
			}
		}
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= n; ++j)
			{
				printf("%5d",f[i][j]);
			}
			cout<<endl;
		}
	}
  return 0;
}