#include<cstdio>
#include<cstring>
char str[305];
int dp[305][305][305],K;
int max(int a,int b){return a>b?a:b;}
int main(){
	scanf("%s%d",str,&K); int lens=strlen(str);
	for(int i=0;i<lens;++i)
		for(int k=0;k<=K;++k)
			dp[i][i][k]=1;
	for(int l=1;l<lens;++l)
		for(int i=0;i+l<lens;++i){
			int j=i+l;
			for(int k=0;k<=K;++k){
				dp[i][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]);
				if(k>0) dp[i][j][k]=max(dp[i+1][j-1][k-1]+2,dp[i][j][k]);
				if(str[i]==str[j]) dp[i][j][k]=max(dp[i+1][j-1][k]+2,dp[i][j][k]);
	        }
	    }
	printf("%d\n",dp[0][lens-1][K]);
}