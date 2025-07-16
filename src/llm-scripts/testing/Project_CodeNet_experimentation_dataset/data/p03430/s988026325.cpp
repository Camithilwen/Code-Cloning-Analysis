#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
#define N 305
int n,k,f[N][N][N];char s[N];
int dp(int l,int r,int k){
	if (k<0) return -1000;
	if (l>r) return 0;
	int &res=f[l][r][k];
	if (~res) return res;
	if (l==r) return res=1;
	res=0;
	if (s[l]==s[r]) res=max(res,dp(l+1,r-1,k)+2);
	else res=max(res,max(max(dp(l+1,r,k),dp(l,r-1,k)),dp(l+1,r-1,k-1)+2));
	return res;
}
int main(){
	scanf("%s%d",s+1,&k);n=strlen(s+1);
	memset(f,-1,sizeof(f));
	printf("%d\n",dp(1,n,k));
	return 0;
}