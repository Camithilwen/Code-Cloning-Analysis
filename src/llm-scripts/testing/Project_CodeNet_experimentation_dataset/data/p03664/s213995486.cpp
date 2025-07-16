#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,ans=2e9,SUM,dis[17][17],num[33000],dp[33000][17];
int main(){
	read(n),read(m);
	for (int i=0;i<m;i++){
		int x,y,c;read(x),read(y),read(c);SUM+=c;
		dis[x-1][y-1]=dis[y-1][x-1]=c;
	}
	for (int i=1;i<(1<<n);i++){
		int cnt;
		for (int j=0;j<n;j++) if ((1<<j)&i){
			cnt=j;break;
		}
		num[i]=num[i^(1<<cnt)];
		for (int k=0;k<n;k++) if ((1<<k)&i) num[i]+=dis[k][cnt];
	}
	for (int i=0;i<33000;i++) for (int j=0;j<17;j++)dp[i][j]=-5e8;
	dp[1][0]=0;
	for (int i=1;i<(1<<n);i++){
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++) if ((i&(1<<j))>0 && (i&(1<<k))>0 && dis[j][k]) dp[i][j]=max(dp[i][j],dp[i^(1<<j)][k]+dis[j][k]);
			for (int k=i;k>=0;k=(k-1)&i){
				if (k&(1<<j)) dp[i][j]=max(dp[i][j],dp[i^k|(1<<j)][j]+num[k]);
				if (k==0) break;
			}
		}
		if ((1<<(n-1))&i) ans=min(ans,SUM-dp[i][n-1]);
	}
	write(ans);
}