#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char a[105][105];
int f[2][105][105][105],line[105][105],list[105][105],n,m;
void upd(int &x,int w){
	x=(x<w)?w:x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	int x,y;
	for(int i=1;i<=n;i++){
		for(int p=1;p<=m;p++){
			if(a[i][p]=='E') x=i,y=p;
			line[i][p]=line[i][p-1]+(a[i][p]=='o');
			list[i][p]=list[i-1][p]+(a[i][p]=='o');
		}
	}
	int pre=0,nxt=1,ans=0;
	for(int i=0;i<=n-x;i++,pre^=1,nxt^=1){
		memset(f[nxt],0,sizeof(f[nxt]));
		for(int p=0;p<x;p++){
			for(int j=0;j<=m-y;j++){
				for(int k=0;k<y;k++){
					int w=f[pre][p][j][k],W;
					if(x+i+1<=n-p) W=max(0,line[x+i+1][min(m-k,y+j)]-line[x+i+1][max(j,y-k-1)]);
					else W=0;
					upd(f[nxt][p][j][k],w+W);
					if(x-p-1>i) W=max(0,line[x-p-1][min(m-k,y+j)]-line[x-p-1][max(j,y-k-1)]);
					else W=0;
					upd(f[pre][p+1][j][k],w+W);
					if(y+j+1<=m-k) W=max(0,list[min(n-p,x+i)][y+j+1]-list[max(i,x-p-1)][y+j+1]);
					else W=0;
					upd(f[pre][p][j+1][k],w+W);
					if(y-k-1>j) W=max(0,list[min(n-p,x+i)][y-k-1]-list[max(i,x-p-1)][y-k-1]);
					else W=0;
					upd(f[pre][p][j][k+1],w+W);
					ans=max(ans,f[pre][p][j][k]);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}