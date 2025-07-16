#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,i,j,x,y,w,hd,s,xlh,g[100010],v[21][21],f[100010][21],sy,mx,ans,pr,sz;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		xlh+=w;
		x--;y--;
		v[x][y]=v[y][x]=w;
	}
	mx=1<<n;
	for(s=1;s<mx;s++){
		for(i=0;i<n;i++)if(s&(1<<i)){
			pr=s^(1<<i);
			sz=0;
			for(j=0;j<n;j++)if((s&(1<<j))&&v[i][j])sz+=v[i][j];
			g[s]=g[pr]+sz;break;
		}
		//printf("%d %d\n",s,g[s]);
	}
	memset(f,172,sizeof(f));
	f[1][0]=0;
	for(s=1;s<mx;s++)
	 for(hd=0;hd<n;hd++)if(f[s][hd]>=0){
	 	for(i=0;i<n;i++)if(!(s&(1<<i))&&v[hd][i]){
	 		f[s|(1<<i)][i]=max(f[s|(1<<i)][i],f[s][hd]+v[hd][i]);
		 }
		sy=(mx-1)^s;
		for(i=sy;i;i=(i-1)&sy)f[s|i][hd]=max(f[s|i][hd],f[s][hd]+g[i|(1<<hd)]);
	 }
	 for(i=1;i<mx;i++)ans=max(ans,f[i][n-1]);
	 printf("%d",xlh-ans);
}