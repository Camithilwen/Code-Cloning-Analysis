#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=200 +117;
const int MM=1 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
int a[2*NN][2*NN]={};
bool vis[2*NN][2*NN]={};
int stat[4]={};
int pp[3][2*NN][2]={};
int cnt[3];
int pre[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
bool inside(int x,int y){
	return x>=0&&x<2*n&&y>=0&&y<2*n;
}
void col(int x,int y,int c,int now){
	vis[x][y]=1;
	if(now)a[x][y]^=c;
	for(int i=1;i<=cnt[c];++i){
		for(int j=0;j<4;++j){
			int nx=x+pre[j][0]*pp[c][i][0];
			int ny=y+pre[j][1]*pp[c][i][1];
			if(inside(nx,ny)&&!vis[nx][ny]){
				col(nx,ny,c,now^1);
			}
		}
	}
}
int main(){
	//open();
	n=read();
	int d1=read(),d2=read();
	for(int i=0;i<=2*n;++i){
		int tp=d1-i*i;
		int k=tp>0?sqrt(tp)+0.1:0;
		if(i*i<=d1&&k*k==tp){
			pp[1][++cnt[1]][0]=i;
			pp[1][cnt[1]][1]=k;
		}
		tp=d2-i*i;
		k=tp>0?sqrt(tp)+0.1:0;
		if(i*i<=d2&&k*k==tp){
			pp[2][++cnt[2]][0]=i;
			pp[2][cnt[2]][1]=k;
		}
	}
	for(int i=0;i<2*n;++i){
		for(int j=0;j<2*n;++j){
			if(!vis[i][j])col(i,j,1,1);
		}
	}
	for(int i=0;i<2*n;++i){
		for(int j=0;j<2*n;++j){
			vis[i][j]=0;
		}
	}
	for(int i=0;i<2*n;++i){
		for(int j=0;j<2*n;++j){
			if(!vis[i][j])col(i,j,2,1);
		}
	}
	for(int i=0;i<2*n;++i){
		for(int j=0;j<2*n;++j){
			++stat[a[i][j]];
		}
	}
	int mx=0;
	for(int i=0;i<4;++i)if(stat[i]>stat[mx])mx=i;
		int opcnt=0;
	for(int i=0;i<2*n;++i){
		for(int j=0;j<2*n;++j){
			if(opcnt<n*n&&a[i][j]==mx){
				printf("%d %d\n",i,j);
				++opcnt;
			}
		}
	}
	close();
	return 0;
}