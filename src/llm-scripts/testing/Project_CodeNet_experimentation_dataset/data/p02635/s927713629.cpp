#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=998244353;
int n,K;
#define Maxn 305
char S[Maxn];
int a[Maxn],cnt=0;
int dp[Maxn][Maxn][Maxn];
int main(){
	scanf("%s",S+1);scanf("%d",&K);
	n=strlen(S+1);
	S[n+1]='0';
	n++;
	int lst=0;
	for(int i=1;i<=n;++i)
	    if(S[i]=='0'){
	    	a[++cnt]=i-lst-1;
	    	lst=i;
		}
	reverse(a+1,a+cnt+1);
	int sum=0;
	dp[0][0][0]=1;
	for(int i=0;i<cnt;++i){
		for(int j=0;j<=sum;++j)
		    for(int k=0;k<=j;++k){
		    	dp[i+1][j][k]=dp[i][j][k];
		    	if(k){
		    		dp[i+1][j][k]+=dp[i+1][j][k-1];
		    		if(dp[i+1][j][k]>=Mod)dp[i+1][j][k]-=Mod;
				}
			}
		for(int j=0;j<=sum;++j)
		    for(int k=0;k<=j;++k)
		        for(int l=1;l<=a[i+1];++l){
		        	dp[i+1][j+l][k]+=dp[i][j][k];
		        	if(dp[i+1][j+l][k]>=Mod)dp[i+1][j+l][k]-=Mod;
				}
		sum+=a[i+1];
	}
	int Ans=0;
	for(int i=0;i<=min(K,sum);++i){
		Ans+=dp[cnt][i][i];
		if(Ans>=Mod)Ans-=Mod;
	}
	printf("%d\n",Ans);
	return 0;
}