#include<bits/stdc++.h>
#define N 110
using namespace std;
char s[N][N];
int sum[N][N],h,w,eh,ew;
int dp[N*N/4][N*N/4];
inline int rg(int l,int r,int d,int u){
	if(l>r||d>u) return 0;
	return sum[r][u]-sum[l-1][u]-sum[r][d-1]+sum[l-1][d-1];
}
int solve(int ch,int cw){
	if(!ch&&!cw) return 0;
	if(dp[ch][cw]>=0) return dp[ch][cw];
	int l=ch%eh,r=ch/eh,d=cw%ew,u=cw/ew;
	if(l){
		dp[ch][cw]=max(dp[ch][cw],solve(ch-1,cw)+ (eh-l>r?rg(eh-l,eh-l,max(1+u,ew-d),min(w-d,ew+u)):0) );
	}
	if(r){
		dp[ch][cw]=max(dp[ch][cw],solve(ch-eh,cw)+ (eh+r<=h-l?rg(eh+r,eh+r,max(1+u,ew-d),min(w-d,ew+u)):0) );
	}
	if(d){
		dp[ch][cw]=max(dp[ch][cw],solve(ch,cw-1)+ (ew-d>u?rg(max(1+r,eh-l),min(h-l,eh+r),ew-d,ew-d):0) );
	}
	if(u){
		dp[ch][cw]=max(dp[ch][cw],solve(ch,cw-ew)+ (ew+u<=w-d?rg(max(1+r,eh-l),min(h-l,eh+r),ew+u,ew+u):0) );
	}
	return dp[ch][cw];
}
int main(){
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=w;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if(s[i][j]=='o') sum[i][j]++;
			else if(s[i][j]=='E') eh=i,ew=j;
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(eh*(h-eh)+eh-1,ew*(w-ew)+ew-1));
	return 0;
}