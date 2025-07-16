#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define IN inline
#define RE register
using namespace std;
const int maxn=2e3+5;
int n,m,q;
int l,u,r,d;
int sum[maxn][maxn][3];
char s[maxn];
bool mp[maxn][maxn];
IN int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
IN void work(){
	u=read(),l=read(),d=read(),r=read();
	int v=sum[d][r][0]-sum[d][l-1][0]-sum[u-1][r][0]+sum[u-1][l-1][0];
	int e1=sum[d][r][1]-sum[d][l-1][1]-sum[u][r][1]+sum[u][l-1][1];
	int e2=sum[d][r][2]-sum[d][l][2]-sum[u-1][r][2]+sum[u-1][l][2];
	printf("%d\n",v-e1-e2);
	return;
}
int main(){
// 	freopen("wang.in","r",stdin);
// 	freopen("wang.out","w",stdout);
	n=read(),m=read(),q=read();
	for(RE int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++) mp[i][j]=s[j]-'0';
	}
	for(RE int i=1;i<=n;i++)
	for(RE int j=1;j<=m;j++){
		sum[i][j][0]=sum[i][j-1][0]+sum[i-1][j][0]-sum[i-1][j-1][0]+mp[i][j];
		if(i>1) sum[i][j][1]=sum[i][j-1][1]+sum[i-1][j][1]-sum[i-1][j-1][1]+(mp[i][j]&mp[i-1][j]);
		if(j>1) sum[i][j][2]=sum[i][j-1][2]+sum[i-1][j][2]-sum[i-1][j-1][2]+(mp[i][j]&mp[i][j-1]);
	}
	for(RE int i=1;i<=q;i++) work();
	return 0;
}