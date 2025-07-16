#include<bits/stdc++.h>
#define N 1000006 
using namespace std;
int f[N][2],n;
char s[N];
int main()
{
	f[0][1]=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
	f[i][0]=min(f[i-1][0]+(s[i]^48),f[i-1][1]+10-(s[i]^48)),
	f[i][1]=min(f[i-1][0]+(s[i]^48)+1,f[i-1][1]+9-(s[i]^48));
	printf("%d\n",min(f[n][0],f[n][1]+1));
 } 