#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int meiro[110][110];
int cc;
int w,h;
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};

void dfs(int x,int y){
	meiro[y][x]=-1;
	int i;
	for(i=0;i<4;i++){
		if(x+xx[i]<0||w<=x+xx[i]||y+yy[i]<0||h<=y+yy[i])continue;
		if(meiro[y+yy[i]][x+xx[i]]!=cc)continue;
		dfs(x+xx[i],y+yy[i]);
	}
}

int main() {
	int xs,ys,xg,yg,n,c,d,x,y;
	while(w=in(),h=in()){
		cin>>xs>>ys>>xg>>yg>>n;
		xs--;ys--;xg--;yg--;
		int i;
		memset(meiro,0,sizeof(meiro));
		for(i=0;i<n;i++){
			cin>>c>>d>>x>>y;
			x--;y--;
//cout<<c<<" "<<d<<" "<<x<<" "<<y<<endl;
			if(d==0){
				meiro[y][x]=meiro[y][x+1]=meiro[y][x+2]=meiro[y][x+3]=meiro[y+1][x]=meiro[y+1][x+1]=meiro[y+1][x+2]=meiro[y+1][x+3]=c;
			}else{
				meiro[y][x]=meiro[y][x+1]=meiro[y+1][x]=meiro[y+1][x+1]=meiro[y+2][x]=meiro[y+2][x+1]=meiro[y+3][x]=meiro[y+3][x+1]=c;
			}
		}
		if(meiro[ys][xs]==0){
			cout<<"NG\n";
			continue;
		}
		cc=meiro[ys][xs];
//cout<<"hoge\n";
		dfs(xs,ys);
//cout<<"piyo\n";
		if(meiro[yg][xg]==-1)cout<<"OK\n";
		else cout<<"NG\n";
	}
	return 0;
}