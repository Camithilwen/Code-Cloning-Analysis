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
const int N = 120000;
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int n,a[N];
void print(int x){
	printf("%s",x==1?"First":"Second");exit(0);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	int now=1;
	while(1){
		int cnt=0,flag=1;
		rep(i,1,n)cnt+=!(a[i]&1),flag&=a[i]==1;
		if(flag)print(3-now);
		if(cnt&1)print(now);
		if(n-cnt!=1)print(3-now);
		rep(i,1,n)if(a[i]&1){if(a[i]==1)print(3-now);a[i]--;}
		int g=0;rep(i,1,n)g=gcd(g,a[i]);
		rep(i,1,n)a[i]/=g;now=3-now;
	}
	return 0;
}
