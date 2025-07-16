#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f,oo = inf;
#define Rep(i,a,b) for(RG int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(RG int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(RG int i=(a);i<int(b);++i)
#define pi 3.14159265358979323846
#define IL inline
#define pc putchar
#define RG register
#define gc getchar
#define fi first
#define se second
#define debug(x) printf(#x" = %d\n",x);
//char __wzp[1<<15|1],*__S=__wzp+32768;
//#define gc() (__S>=__wzp+32768?(__wzp[fread(__wzp,sizeof(char),1<<15,stdin)]=EOF),*((__S=__wzp)++):*(__S++))
#define rd read
#define mem(x,v) memset(x,v,sizeof(x))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
inline ll read(){
	RG ll x=0,f=1;RG char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
IL double readdb(){
    RG double x=0,p=0.1;RG char f=0,c=gc();
    for(;!isdigit(c);c=gc())f|=(c=='-');
    for(;isdigit(c);c=gc())x=x*10+(c^48);
    if(c=='.')for(c=gc();isdigit(c);c=gc(),p/=10)x=x+(c^48)*p;
    return f?-x:x;
}
#define rdb() readdb()
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
int color[2][1005][1005];
int db[2<<17],n;
const int dx[] = {1,1,-1,-1};
const int dy[] = {1,-1,1,-1};
void dfs(int x,int y,int d,int col,int c){
	color[c][x][y] = col;
	for(int i=0;i*i<=d;i++){
		if(db[d-i*i]<0)continue;
		int j = db[d-i*i];
		rep(r,0,4){
			int tx = x+dx[r]*i;
			int ty = y+dy[r]*j;
			if(tx<0||ty<0||tx>=2*n||ty>=2*n||color[c][tx][ty]) continue;
			dfs(tx,ty,d,col==1?2:1,c);
		}
	}
}
int main(){
	n = rd();
	rep(i,0,2<<17) db[i] = -1;
	for(int i=0;i*i<(2<<17);++i) db[i*i] = i;
	rep(i,0,2){
		int d = rd();
		rep(x,0,2*n)
			rep(y,0,2*n)
				if(!color[i][x][y])
					dfs(x,y,d,1,i);
	}
	vector<pair<int,int> > a;
	rep(x,0,2*n)
		rep(y,0,2*n)
			if(color[0][x][y]==1&&color[1][x][y]==1)
				a.push_back(make_pair(x,y)); 
	rep(i,0,n*n)
		printf("%d %d\n",a[i].fi,a[i].se);
}













