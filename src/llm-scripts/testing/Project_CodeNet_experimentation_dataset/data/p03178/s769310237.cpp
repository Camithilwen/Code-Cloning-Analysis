#include<bits/stdc++.h>

using namespace std;
const int MAXN=10005;
int P=1e9+7,d,len;
char k[MAXN];
long long a[MAXN],dp[10005][105];

long long dfs(int pos,int tot,bool lim)
{
//	cout<<pos<<' '<<tot<<' '<<lim<<endl;
	if(pos==len+1)
	{
		if(tot==0)	return 1;
		return 0;
	} 
	if(!lim&&dp[pos][tot]!=-1) return dp[pos][tot];
	
	long long ret=0 ,  up=lim?a[pos]:9  ;
	
	for(int i=0;i<= up  ;++i)
	{
		ret=(ret+dfs(pos+1,(tot+i)%d, lim&&i==a[pos] ))%P;
		
		//(ret+=dfs(pos+1,(tot+i)%d, lim&&i==a[pos] ) )%=P;
	}
	
	if(!lim) dp[pos][tot]=ret;
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%s",k+1);
	scanf("%d",&d);
	len=strlen(k+1);
	for(int i=1;i<=len;++i)
	{
		a[i]=k[i]-'0';
	}
	
	long long ans=(dfs(1,0,1)-1+P)%P;  
	printf("%lld\n",ans);
	return 0;
}
