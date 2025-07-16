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
typedef pair<Pii,Pii> Ppp;
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
const int N = 606;
int n,d1,d2;vector<Pii> res;
void solve(int d1, int d2, vector<Ppp> s){//now,real
	vector<Ppp> a,b;
	rep(i,0,SZ(s)-1)if(!((s[i].fi.fi+s[i].fi.se)&1)){
		a.pb(Ppp(Pii((s[i].fi.fi+s[i].fi.se)/2,(s[i].fi.se-s[i].fi.fi)/2),s[i].se));
	}
	else{
		s[i].fi.fi++;
		b.pb(Ppp(Pii((s[i].fi.fi+s[i].fi.se)/2,(s[i].fi.se-s[i].fi.fi)/2),s[i].se));
	}
	if(SZ(a)<SZ(b))swap(a,b);
	if(d1&d2&1)rep(i,0,SZ(a)-1)res.pb(a[i].se);
	else{
		bool bo=0;if(d2&1)d2=d1,bo=1;if(d1&1)d1=d2,bo=1;
		if(bo)solve(d1/2,d2/2,a);
		else{solve(d1/2,d2/2,a);solve(d1/2,d2/2,b);}
	}
}
int getdis(Pii a, Pii b){return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);}
int main() {
	read(n);read(d1);read(d2);
	vector<Ppp>d;rep(i,0,n*2-1)rep(j,0,n*2-1)d.pb(Ppp(Pii(i,j),Pii(i,j)));
	solve(d1,d2,d);
//	rep(i,0,SZ(res)-1)rep(j,i,SZ(res)-1)assert(d1!=(getdis(res[i],res[j]))&&d2!=(getdis(res[i],res[j])));
//	assert(SZ(res)>=n*n);
	rep(i,0,n*n-1)printf("%d %d\n",res[i].fi,res[i].se);
	return 0;
}
