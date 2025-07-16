#include<stdio.h>
#include<string.h>
char s[524288];
int dp[4],dp2[4];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	s[n]='1';
	n++;
	dp[2]=1;
	int ans=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			dp2[j]=dp[j];
			dp[j]=0;
		}
		for(int j=0;j<4;j++)
		{
			dp[j&1]+=dp2[j];
			if(dp[j&1]>=1000000007)
			{
				dp[j&1]-=1000000007;
			}
		}
		for(int j=0;j<4;j++)
		{
			if(i&1)
			{
				if(j==3)
				{
					continue;
				}
				dp[j|2]+=dp2[j];
				if(dp[j|2]>=1000000007)
				{
					dp[j|2]-=1000000007;
				}
			}
			else
			{
				dp[2+(j!=0)]+=dp2[j];
				if(dp[2+(j!=0)]>=1000000007)
				{
					dp[2+(j!=0)]-=1000000007;
				}
			}
		}
		if(s[i]=='1')
		{
			dp[0]=0;
			dp[1]=0;
		}
		else if(s[i]=='0')
		{
			dp[2]=0;
			dp[3]=0;
		}
		else
		{
			ans<<=1;
			if(ans>=1000000007)
			{
				ans-=1000000007;
			}
		}
	}
	ans-=dp[2];
	if(ans<0)
	{
		ans+=1000000007;
	}
	ans-=dp[3];
	if(ans<0)
	{
		ans+=1000000007;
	}
	printf("%d\n",ans);
	return 0;
}