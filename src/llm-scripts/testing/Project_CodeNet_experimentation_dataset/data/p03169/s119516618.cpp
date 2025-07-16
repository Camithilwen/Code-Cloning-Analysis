#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
int n;
double sushi(int o,int z, int t){
	if(z<0||o<0||t<0)
	return 0.0;
	if(z==0&&o==0&&t==0)
	return 0.0;
	if(dp[o][z][t]>=0.0)
	return (double) dp[o][z][t];
	dp[o][z][t]= o*sushi(o-1,z,t)+z*sushi(o+1,z-1,t)+t*sushi(o,z+1,t-1)+n;
	dp[o][z][t]/=(o+z+t);
	return dp[o][z][t];
}
int main(){
	
	int  o=0,z=0,t=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	if(a[i]==2)
	z++;
	else if(a[i]==1)
	o++;
	else
	t++;
	}
	memset(dp,-1.0,sizeof (dp));
	dp[0][0][0]=0.0;

	cout<<fixed<<setprecision(12)<<sushi(o,z,t);
	
	
	
}