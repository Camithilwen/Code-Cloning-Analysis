#include <bits/stdc++.h>
#define re register
#define SIZE 10005
#define LL long long 
#define MOD 1000000007
using namespace std;
string k;
int d;
int maxn[SIZE],cnt;
LL dp[SIZE][105];
inline LL dfs(int pos,int sta,bool lim)
{
	if(pos>cnt)
		return sta==0?1:0;
	if(!lim && dp[pos][sta]!=-1)
		return dp[pos][sta];
	int up=lim?maxn[pos]:9;
	LL ret=0;
	for(re int i=0;i<=up;++i)
		ret=(ret+dfs(pos+1,(sta+i)%d,lim&&(i==maxn[pos])))%MOD;
	if(!lim)
		dp[pos][sta]=ret;
	return ret;
}
inline LL work()
{
	memset(dp,-1,sizeof(dp));
	cnt=k.size()-1;
	for(re int i=0;i<=cnt;++i)
		maxn[i]=k[i]-'0'; 
	return dfs(0,0,1);
}
int main()
{
	cin>>k;
	cin>>d;
	LL ans=(work()-1+MOD)%MOD;
	printf("%lld\n",ans);
	return 0;
} 
//3373