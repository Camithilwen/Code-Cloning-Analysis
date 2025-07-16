#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int mod = 1e9+7;
void ad(int &x,int y) { x+=y; if(x>=mod)x-=mod; }
int zy[8][2] = {{6,1},{3,2},{2,2},{4,1},{3,3},{6,1},{7,5},{6,6}};
char ss[300005];
int n;
int dp[300005][8];
int main() {
	scanf("%s",&ss[1]);
	n = strlen(ss+1);
	dp[0][0] = 1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<8;j++) {
			if(ss[i+1]!='0') ad(dp[i+1][zy[j][1]],dp[i][j]);
			if(ss[i+1]!='1') ad(dp[i+1][zy[j][0]],dp[i][j]);
		}
	}
	int ans = (dp[n][1] + dp[n][2])%mod;
	printf("%d",ans);
}