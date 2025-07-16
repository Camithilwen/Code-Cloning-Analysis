#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long LL;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
const int N=110;
int h[N][N],u[N][N];
int f[N][N][N],g[N][N][N];
inline void upd(int &x,int y) { x<y?x=y:0; }
int main()
{
	int n=gi(),m=gi(),i,j,x,y,lx,rx,ly,ry,t;
	char c;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) {
			h[i][j]=h[i][j-1];u[i][j]=u[i-1][j];
			while ((c=getchar())!='.'&&c!='E'&&c!='o');
			if (c=='E') x=i,y=j;
			else if (c=='o') h[i][j]++,u[i][j]++;
		}
	for (lx=0;lx<x;lx++) {
		memcpy(g,f,sizeof(g));
		memset(f,0,sizeof(f));
		for (rx=0;rx<=n-x;rx++)
			for (ly=0;ly<y;ly++)
				for (ry=0;ry<=m-y;ry++) {
					t=g[rx][ly][ry];
					upd(f[rx][ly][ry],t+(x-lx-1>rx?h[x-lx-1][min(y+ry,m-ly)]-h[x-lx-1][max(y-ly-1,ry)]:0));
					upd(g[rx+1][ly][ry],t+(x+rx+1<=n-lx?h[x+rx+1][min(y+ry,m-ly)]-h[x+rx+1][max(y-ly-1,ry)]:0));
					upd(g[rx][ly+1][ry],t+(y-ly-1>ry?u[min(x+rx,n-lx)][y-ly-1]-u[max(x-lx-1,rx)][y-ly-1]:0));
					upd(g[rx][ly][ry+1],t+(y+ry+1<=m-ly?u[min(x+rx,n-lx)][y+ry+1]-u[max(x-lx-1,rx)][y+ry+1]:0));
				}
	}
	printf("%d\n",g[n-x][y-1][m-y]);
	return 0;
}
