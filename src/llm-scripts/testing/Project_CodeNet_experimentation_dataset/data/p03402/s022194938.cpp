#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5,inf=0x3f3f3f3f;
char s[N][N];
int a,b,n=100;
int main()
{
	cin>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(j>50)
				s[i][j]='#';
			else
				s[i][j]='.';
		}
	for(int i=1;i<=n;i+=2)
		for(int j=1;j<50;j++)
		{
			if((i+j)%2&&b!=1)
				s[i][j]='#',b--;
		}
	for(int i=1;i<=n;i+=2)
		for(int j=51;j<=100;j++)
		{
			if((i+j)%2&&a!=1)
				s[i][j]='.',a--;
		}
	puts("100 100");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%c",s[i][j]);
		printf("\n");
	}
		
	return 0;
}