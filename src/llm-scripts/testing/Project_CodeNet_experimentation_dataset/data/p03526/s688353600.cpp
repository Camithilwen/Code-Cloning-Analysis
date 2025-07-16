#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 5050,inf=0x3f3f3f3f;
int n,f[N][N],res;
struct node{
	int p,h;
}a[N];
bool cmp(node a, node b){
//	return a.p+a.h<b.p+b.h;
	return min(a.h,b.h-a.p)>min(b.h,a.h-b.p);
}
int main() {
	read(n);rep(i,1,n)read(a[i].h),read(a[i].p);
	sort(a+1,a+n+1,cmp);
	rep(i,0,n)rep(j,0,n)f[i][j]=inf;f[0][0]=0;
	rep(i,0,n-1)rep(j,0,i)if(f[i][j]<inf){
		umin(f[i+1][j],f[i][j]);
		if(f[i][j]<=a[i+1].h)umin(f[i+1][j+1],f[i][j]+a[i+1].p),umax(res,j+1);
	}
	cout<<res;
	return 0;
}
