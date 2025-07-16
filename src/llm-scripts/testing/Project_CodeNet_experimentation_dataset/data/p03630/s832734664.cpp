#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=2005;

int n,m,t,ans;
int dp[N][N],mp[N][N],st[N],f[N],g[N];
char s[N][N];

bool pd(int x1,int y1,int x2,int y2){
	int sum;
	sum=mp[x1][y1]+mp[x1][y2]+mp[x2][y1]+mp[x2][y2];
	return !(sum&1);
}

void init(){
	int i,j,k;
	for (i=1;i<n;i++){
		for (j=m-1;j;j--){
			if (pd(i,j,i+1,j+1)) dp[i][j]=dp[i][j+1]+1;
			else dp[i][j]=0;
		}
	}
}

void work(){
	int i,j;
	for (i=1;i<m;i++){
		t=0;
		for (j=1;j<n;j++){
			while (t&&dp[j][i]<dp[st[t]][i]){
				f[st[t]]=j; t--;
			}
			st[++t]=j;
		}
		for (j=1;j<=t;j++) f[st[j]]=n;
		t=0;
		for (j=n-1;j;j--){
			while (t&&dp[j][i]<dp[st[t]][i]){
				g[st[t]]=j+1; t--;
			}
			st[++t]=j;
		}
		for (j=1;j<=t;j++) g[st[j]]=1;
		for (j=1;j<n;j++) ans=max(ans,(f[j]-g[j]+1)*(dp[j][i]+1));
	}
}

int main(){
	int i,j;
	scanf("%d%d",&n,&m); ans=max(n,m);
	for (i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (j=1;j<=m;j++) mp[i][j]=s[i][j]=='.';
	}
	init();
	work();
	printf("%d\n",ans);
	return 0;
}