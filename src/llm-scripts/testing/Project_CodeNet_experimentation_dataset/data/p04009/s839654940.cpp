#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int xe,ye;
short n,m,ans,a[maxn][maxn],p=0,np=1,dp[2][maxn][maxn][maxn];
char c[maxn][maxn];
void inline upd(short& x,short y){
	if(x<y){x=y;if(y>ans)ans=y;}
}
int inline z(int i,int j,int k,int l){
	return a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1];
}
int inline cal1(int w,int h,int x,int l,int r){
	int ret=0,_w=n-w,_h=m-h;
	if(ye>1+_h)return 0;
	else return z(max(l,xe-_w+l-1),x,min(r,xe+l-1),x);
}
int inline cal2(int w,int h,int y,int l,int r){
	int ret=0,_w=n-w,_h=m-h;
	if(xe>1+_w)return 0;
	else return z(y,max(l,ye+l-_h-1),y,min(r,ye+l-1));
}
int inline cal3(int w,int h,int x,int l,int r){
	int ret=0,_w=n-w,_h=m-h;
	if(ye<h)return 0;
	else return z(max(l,xe-_w+l-1),x,min(r,xe+l-1),x);
}
int inline cal4(int w,int h,int y,int l,int r){
	int ret=0,_w=n-w,_h=m-h;
	if(xe<w)return 0;
	else return z(y,max(l,ye-_h+l-1),y,min(r,ye+l-1));
}
int main(){
//	freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			a[i][j]=(c[i][j]=='o')+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			if(c[i][j]=='E')xe=i,ye=j;
		}
	dp[np][1][1][m]=ans=1;
	for(int k=n;k>=1;--k,swap(p,np))for(int l=m;l>=1;--l)
		for(int i=1;i<=n-k+1;++i)for(int j=1;j<=m-l+1;++j)if(dp[np][i][j][l]){
			int x=dp[np][i][j][l];
//			printf("{%d,%d,%d,%d,%d}\n",i,j,k,l,x);
			upd(dp[np][i][j+1][l-1],x+cal1(k,l,j,i,i+k-1));
			upd(dp[p][i+1][j][l],x+cal2(k,l,i,j,j+l-1));
			upd(dp[np][i][j][l-1],x+cal3(k,l,j+l-1,i,i+k-1));
			upd(dp[p][i][j][l],x+cal4(k,l,i+k-1,j,j+l-1));
			dp[np][i][j][l]=0;
		}
	printf("%d",ans-1);
}