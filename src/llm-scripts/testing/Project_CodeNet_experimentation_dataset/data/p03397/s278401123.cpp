#include<cstdio>
#include<cstring>
#define N 300010
using namespace std;
int to[8][2]={2,1,
			  3,5,
			  4,7,
			  6,1,
			  2,2,
			  5,5,
			  3,3,
			  2,1};
char s[N];
int f[N][8];
const int p=1e9+7;
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	f[n][1]=f[n][5]=1;
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<8;j++)
		{
			if(s[i]!='1') f[i][j]+=f[i+1][to[j][0]];
			if(s[i]!='0') f[i][j]+=f[i+1][to[j][1]];
			f[i][j]%=p;
		}
	printf("%d",f[0][0]);
	return 0;
} 