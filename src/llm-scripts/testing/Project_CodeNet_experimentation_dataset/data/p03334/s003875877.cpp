#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<ctime>
#include<cstdlib>
#define MP make_pair
#define fi first
#define se second 
#define pb push_back
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int N=610;
bool vis[N][N];
int col[N][N];int f[N][N];
int sz[5];
vector<pair<int,int> > fob;
int n,m;

void dfs(int x,int y){
	int i,dx,dy;
	vis[x][y]=1;
	rep(i,0,(int)fob.size()-1){
		dx=x+fob[i].fi;
		dy=y+fob[i].se;
		if(0<=dx&&dx<2*n&&0<=dy&&dy<2*n&&!vis[dx][dy]){
			col[dx][dy]=col[x][y]^1;
			dfs(dx,dy);
		}
	}
}

void work(int D,int B){
	register int i,j;
	fob.clear();
	memset(vis,0,sizeof(vis));
	memset(col,0,sizeof(col));
	rep(i,0,2*n-1) rep(j,0,2*n-1) if(i*i+j*j==D){
		fob.pb(MP(i,j));
		fob.pb(MP(-i,j));
		fob.pb(MP(i,-j));
		fob.pb(MP(-i,-j));
	}
	rep(i,0,2*n-1)	rep(j,0,2*n-1) if(!vis[i][j]) dfs(i,j);
	rep(i,0,2*n-1)	rep(j,0,2*n-1) if(col[i][j]) f[i][j]^=B;
}

void print(int ty){
	int cnt=0;
	int i,j;
	rep(i,0,2*n-1)	rep(j,0,2*n-1) if(f[i][j]==ty){
		cnt++;
		printf("%d %d\n",i,j);
		//cerr<<cnt<<endl;
		if(cnt==n*n)	return;
	}
} 

int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//srand(20010102);
	register int i,j;
	int D;
	scanf("%d",&n);
	scanf("%d",&D);work(D,1);
	scanf("%d",&D);work(D,2);
	rep(i,0,2*n-1)	rep(j,0,2*n-1)	sz[f[i][j]]++;
	rep(i,0,3)	if(sz[i]>=n*n)	{print(i);return 0;}
	return 0;
}






















