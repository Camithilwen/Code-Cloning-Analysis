#include<bits/stdc++.h>
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,size,stdin),p1==p2)?EOF:*p1++)
#define mk make_pair
#define pi pair<int,int>
#define pb push_back
#define IT iterator
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N=4e5+10,size=1<<20,mod=998244353;
const ll inf=1e18;

template<class o> void qr(o &x) {
	char c=gc; x=0; int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=gc;}
	while(isdigit(c)) x=x*10+c-'0',c=gc;
	x*=f;
}
template<class o> void qw(o x) {
	if(x/10) qw(x/10);
	putchar(x%10+'0');
}
template<class o> void pr1(o x) {
	if(x<0)x=-x,putchar('-');
	qw(x); putchar(' ');
}
template<class o> void pr2(o x) {
	if(x<0)x=-x,putchar('-');
	qw(x); puts("");
}


int n,dic[150],f[N*2][2],g[N*2][2];
ll ans=inf;
vector<pi> x[N],y[N];

int main() {
	qr(n);
	dic['U']=0;
	dic['D']=1;
	dic['R']=2;
	dic['L']=3;
	for(int i=1;i<=n;i++) {
		int a,b,c;qr(a); qr(b);
		char str[6]; scanf("%s",str);
		a++; b++; c=dic[str[0]];
		x[a].pb(mk(b,c));
		y[b].pb(mk(a,c));
	}
	for(int i=1;i<N;i++) {
		sort(all(x[i]));
		sort(all(y[i]));
		ll a,b;
		a=b=inf;
		for(auto j:x[i]) {
			if(j.se==0) a=j.fi;
			else if(j.se==1) b=j.fi;
			if(a<b) ans=min(ans,(b-a)*5);
		}
		a=b=inf;
		for(auto j:y[i]) {
			if(j.se==2) a=j.fi;
			else if(j.se==3) b=j.fi;
			if(a<b) ans=min(ans,(b-a)*5);
		}
	}
	for(int i=1;i<N;i++) 
		for(auto j:x[i]) {
			int t=j.fi;
			if(j.se==2) {
				f[j.fi-i+N][0]=i;
				f[j.fi+i][1]=i;
			}
			else if(j.se==3) {
				int k=g[j.fi+i][1];
				if(k) ans=min(ans,(i-k)*10LL);
				k=g[j.fi-i+N][0];
				if(k) ans=min(ans,(i-k)*10LL);
			}
			else if(j.se==1) {
				int k=f[j.fi-i+N][0];
				if(k) ans=min(ans,(i-k)*10LL);
				g[j.fi+i][1]=i;
			}
			else if(j.se==0) {
				int k=f[j.fi+i][1];
				if(k) ans=min(ans,(i-k)*10LL);
				g[j.fi-i+N][0]=i;
			}
		}
	if(ans>inf/2) puts("SAFE");
	else pr2(ans);
	return 0;
}

