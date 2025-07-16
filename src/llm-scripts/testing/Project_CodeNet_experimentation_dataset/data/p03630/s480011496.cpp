#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 2200
using namespace std;
int a[N][N],f[N][N],l[N],r[N],b[N],id[N];
int n,m,ans;
char s[N];
int check(int x,int y){
	return ((a[x][y]==a[x-1][y])&&(a[x][y-1]==a[x-1][y-1]))||((a[x][y]!=a[x-1][y])&&(a[x][y-1]!=a[x-1][y-1]));
}
bool cmp(int x,int y){
	return b[x]>b[y];
}
int solve(){
	for(int i=1;i<=n;i++)id[i]=i;
	sort(id+1,id+1+n,cmp);
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for(int i=1;i<=n;i++){
		int x=id[i];
		l[x]=x;
		r[x]=x;
		if(l[x-1])l[x]=min(l[x],l[x-1]);
		if(r[x+1])r[x]=max(r[x],r[x+1]);
		r[l[x]]=r[x];
		l[r[x]]=l[x];
		ans=max(ans,(r[x]-l[x]+1)*b[x]+((l[x]-1>0)?b[x]:0));
		l[0]=0;
		r[0]=0;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)a[i][j]=s[j]=='.';
	}
	for(int i=1;i<=m;i++)f[1][i]=i;
	for(int i=2;i<=n;i++){
		f[i][1]=1;
		for(int j=2;j<=m;j++){
			if(check(i,j))f[i][j]=f[i][j-1]+1;
			else f[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)b[j]=f[j][i];
		solve();
	}
	printf("%d\n",ans);
}