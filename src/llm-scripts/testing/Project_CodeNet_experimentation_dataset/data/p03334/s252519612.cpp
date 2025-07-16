#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
    int x=0,p=1;char c=getchar();
    while (c<=32)c=getchar();
    if(c==45)p=-p,c=getchar();
    while (c>32)x=x*10+c-48,c=getchar();
    return x*p;
}
using namespace std;
//ruogu_alter
const int N=605;
int dx[]={1,-1,-1,1};
int dy[]={-1,1,-1,1};
int n,cnt[2][2];
int col[N][N][2];
vector<pii >g[N][N];
bool vis[N][N];
//
inline bool isvalid(int x,int y){
	if(x<0||x>=2*n||y<0||y>=2*n)return false;
	return true;
}
void go(int x,int y,int z,int c){
	col[x][y][z]=c;
	vis[x][y]=true;
	rep(i,g[x][y].size()){
		pii u=g[x][y][i];
		if(!vis[u.first][u.second]){
			go(u.first,u.second,z,c^1);
		}
	}
}
void solve(int d,int x){
	rep(i,2*n)rep(j,2*n)g[i][j].clear();
	rep(i,2*n)if(i*i<=d){
		int j=sqrt(d-i*i);
		if(j*j+i*i!=d)continue;
		rep(x,2*n)rep(y,2*n)rep(k,4){
			int fx=x+i*dx[k],fy=y+j*dy[k];
			if(!isvalid(fx,fy))continue;
			g[x][y].push_back(mp(fx,fy));
		}
	}
	rep(i,2*n)rep(j,2*n)vis[i][j]=false;
	rep(i,2*n)rep(j,2*n)if(!vis[i][j]){
		go(i,j,x,0);
	}
}
int main(){
	n=getint();
	rep(i,2){
		int x=getint();
		solve(x,i);
	}
	rep(i,2*n)rep(j,2*n)cnt[col[i][j][0]][col[i][j][1]]++;
	rep(i,2)rep(j,2)if(cnt[i][j]>=n*n){
		int c=0;
		rep(x,2*n)rep(y,2*n){
			if(col[x][y][0]==i&&col[x][y][1]==j){
				printf("%d %d\n",x,y);
				++c;
			}
			if(c==n*n)return 0;
		}
		return 0;
	}
	return 0;
}
