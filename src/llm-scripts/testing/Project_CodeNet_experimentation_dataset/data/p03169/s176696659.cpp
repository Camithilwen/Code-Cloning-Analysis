#include <bits/stdc++.h>
#define re register
#define SIZE 305
#define INF 0x7f7f7f
using namespace std;
int n;
int a[SIZE];
int cnt[5];
double dp[SIZE*3][SIZE*2][SIZE],ans=0;
inline double dfs(int i,int j,int k)
{ 
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	dp[i][j][k]=0;
	double x=i*1.0,y=j*1.0,z=k*1.0;
	double m=x+y+z;
	if(i+j+k<n)
		dp[i][j][k]+=dfs(i+1,j,k)*(x+1)/(m+1);
	if(i-1>=0)
		dp[i][j][k]+=dfs(i-1,j+1,k)*(y+1)/m;
	if(j-1>=0)
		dp[i][j][k]+=dfs(i,j-1,k+1)*(z+1)/m;
	return dp[i][j][k];
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
		scanf("%d",&a[i]),++cnt[a[i]];
	for(re int i=0;i<=cnt[3]+cnt[2]+cnt[1]+1;++i)
		for(re int j=0;j<=cnt[3]+cnt[2]+1;++j)
			for(re int k=0;k<=cnt[3]+1;++k)
				if(i>cnt[3]+cnt[2]+cnt[1] || j>cnt[3]+cnt[2] || k>cnt[3])
					dp[i][j][k]=0;
				else
					dp[i][j][k]=-1;
	dp[cnt[1]][cnt[2]][cnt[3]]=1;
	for(re int i=0;i<=cnt[3]+cnt[2]+cnt[1];++i)
		for(re int j=0;j<=cnt[3]+cnt[2];++j)
			for(re int k=0;k<=cnt[3];++k)
			{
				if(i==0 && j==0 && k==0)
					continue; 
				ans+=(double) (dfs(i,j,k)*n)/(double) (i+j+k);
			}
	printf("%.10lf\n",ans);
	return 0;
} 