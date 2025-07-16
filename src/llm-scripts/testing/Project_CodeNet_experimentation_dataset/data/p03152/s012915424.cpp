#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int a[N],b[N],col,n,m,com,tot;
const long long mod=1e9+7;
long long ans=0;
bool vis[2][N*N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		vis[0][a[i]]=true;
	}
	for(int j=1;j<=m;j++) {
		scanf("%d",&b[j]);
		vis[1][b[j]]=true;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	ans=1;
	for(int i=1;i<n;i++) if(a[i]==a[i+1]) ans=0;
	for(int j=1;j<m;j++) if(b[j]==b[j+1]) ans=0;
	col=n;com=m;
	for(int i=m*n;i>=1;i--){
		while(col>=1&&a[col]>=i) col--;
		while(com>=1&&b[com]>=i) com--;
		tot=(n-col)*(m-com)-(n*m-i);
		if(tot<=0) ans=0;
		if(vis[0][i]&&vis[1][i]) tot=1;
		else if(vis[0][i]) tot=m-com;
		else if(vis[1][i]) tot=n-col;
		ans=ans*tot%mod;
	}
	printf("%lld\n",ans);
	
	
}