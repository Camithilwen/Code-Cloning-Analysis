#include <bits/stdc++.h>
using namespace std;
const int MAXN=300100,MOD=1e9+7;
const int automata[8][2]={{3,1},{5,2},{2,2},{4,7},{3,3},{6,1},{5,5},{3,1}};
char ch[MAXN];
int dp[MAXN][8],len;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>ch;
	len=strlen(ch);
	dp[len][1]=dp[len][2]=1;
	for(register int i=len-1;~i;i--)
		for(register int j=0;j<8;j++)
		{
			if(ch[i]!='0') dp[i][j]=(dp[i][j]+dp[i+1][automata[j][1]])%MOD;
			if(ch[i]!='1') dp[i][j]=(dp[i][j]+dp[i+1][automata[j][0]])%MOD;
		}
	cout<<dp[0][0]<<endl;
	return 0;
}