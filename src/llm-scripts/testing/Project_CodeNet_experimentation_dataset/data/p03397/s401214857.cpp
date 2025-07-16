#include <bits/stdc++.h>
using namespace std;
#define N 300100
const int mod=1e9+7;

int a[8][2],f[N][8];
char s[N];

int main()
{
	a[0][0]=1; a[0][1]=2;
	a[1][0]=3; a[1][1]=4;
	a[2][0]=5; a[2][1]=6;
	a[3][0]=a[3][1]=1;
	a[4][0]=1; a[4][1]=2;
	a[5][0]=7; a[5][1]=2;
	a[6][0]=a[6][1]=6;
	a[7][0]=a[7][1]=5;
	scanf("%s",s);
	int n=strlen(s);
	f[n][2]=f[n][6]=1;
	for (int i=n-1;i>=0;i--)
		for (int j=0;j<8;j++)
		{
			if (s[i]!='1') (f[i][j]+=f[i+1][a[j][0]])%=mod;
			if (s[i]!='0') (f[i][j]+=f[i+1][a[j][1]])%=mod;
		}
	printf("%d\n",f[0][0]);
	return 0;
}