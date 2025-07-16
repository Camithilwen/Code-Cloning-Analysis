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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1060000,mo=998244353,inv2=(mo+1)/2;
int n,m,fac[N],ifac[N];
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}
int main() {
	read(n);read(m);if(n>m)swap(n,m);
	int mx=N-1;fac[0]=1;rep(i,1,mx)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[mx]=power(fac[mx],mo-2);per(i,mx-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	ll res=m;int ni=power(C(n+m,n),mo-2);
	rep(i,0,n-1)res=(res+1LL*inv2*C(n-i+n-i,n-i)%mo*C(i+i+m-n,i)%mo*ni)%mo;cout<<res;
	return 0;
}
