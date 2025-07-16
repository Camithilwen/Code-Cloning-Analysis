#include<cstdio>
using namespace std;
#define N 300050
#define M 10
#define mod 1000000007
int dp[N][M],t[M][2],as;
char s[N];
int main()
{
	t[1][1]=2;t[1][0]=8;
	t[2][1]=3;t[2][0]=4;
	t[3][1]=3;t[3][0]=3;
	t[4][1]=2;t[4][0]=5;
	t[5][1]=4;t[5][0]=4;
	t[6][1]=2;t[6][0]=7;
	t[7][1]=6;t[7][0]=9;
	t[8][1]=6;t[8][0]=9;
	t[9][1]=8;t[9][0]=8;
	scanf("%s",s+1);
	dp[0][1]=1;
	for(int i=1;s[i];i++)
	{
		if(s[i]!='0')for(int j=1;j<10;j++)dp[i][t[j][1]]=(dp[i][t[j][1]]+dp[i-1][j])%mod;
		if(s[i]!='1')for(int j=1;j<10;j++)dp[i][t[j][0]]=(dp[i][t[j][0]]+dp[i-1][j])%mod;
		as=(dp[i][3]+dp[i][2])%mod;
	}
	printf("%d\n",as);
}//