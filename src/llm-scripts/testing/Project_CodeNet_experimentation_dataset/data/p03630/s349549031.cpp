#include<bits/stdc++.h>

using namespace std;

#define N 2005

int n,m,f[N][N],L[N],R[N],ans,stk[N];
bool a[N][N];
char s[N];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%s",s+1);
		for (int j=1;j<=m;++j) a[i][j]=s[j]=='.';
	}
	for (int i=n;i;--i){
		for (int j=1;j<m;++j)
			if ((a[i][j]^a[i][j+1])==(a[i+1][j]^a[i+1][j+1])) f[i][j]=f[i+1][j]+1;
			else f[i][j]=1;
	}
	ans=n;
	for (int i=1;i<=n;++i){
		int tp=0; stk[tp]=0;
		for (int j=1;j<m;++j){
			for (;tp&&f[i][j]<f[i][stk[tp]];--tp);
			L[j]=stk[tp];
			stk[++tp]=j;
		}
		tp=0; stk[tp]=m;
		for (int j=m-1;j;--j){
			for (;tp&&f[i][j]<=f[i][stk[tp]];--tp);
			R[j]=stk[tp];
			stk[++tp]=j;
		}
		for (int j=1;j<m;++j)
			ans=max(ans,f[i][j]*(R[j]-L[j]));
	}
	printf("%d\n",ans);
	
	return 0;
}
			