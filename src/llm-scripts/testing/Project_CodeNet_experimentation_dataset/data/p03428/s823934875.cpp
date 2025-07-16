#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

//#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
//typedef pair<int,int> P;
//typedef pair<int,P> PP;

//-----------------------------------------------------------------------------

const double EPS=1e-8;
const double INF=1e12;

typedef complex<double> P;

namespace std {
	bool operator<(const P &a,const P &b) {
		return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
	}
}

double cross(const P &a,const P &b) {
	return imag(conj(a)*b);
}

double dot(const P &a,const P &b) {
	return real(conj(a)*b);
}

int ccw(P a,P b,P c) {
	b-=a;c-=a;
	if(cross(b,c)>0) 	return +1;
	if(cross(b,c)<0) 	return -1;
	if(dot(b,c)<0)	 	return +2;
	if(norm(b)<norm(c)) return -2;
	return 0;
}

vector<P> convex(vector<P> ps) {
	int n=(int)ps.size(),k=0;
	sort(ALL(ps));
	vector<P> ch(2*n);
	for(int i=0;i<n;ch[k++]=ps[i++]) {
		while(k>=2&&ccw(ch[k-2],ch[k-1],ps[i])<=0) --k;
	}
	for(int i=n-2,t=k+1;i>=0;ch[k++]=ps[i--]) {
		while(k>=t&&ccw(ch[k-2],ch[k-1],ps[i])<=0) --k;
	}
	ch.resize(k-1);
	return ch;
}

int n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;
	vector<P> ps;
	map<P,int> idx;
	REP(i,n) {
		double x,y;cin>>x>>y;
		ps.pb(P(x,y));
		idx[P(x,y)]=i;
	}
	vector<double> ans(n,0.0);
	vector<P> res=convex(ps);

	int sz=(int)res.size();
	if(sz==2) {
		for(auto p:res) ans[idx[p]]=0.5;
	}
	else {
		REP(i,sz) {
			P prv=res[(i-1+sz)%sz],crt=res[i],nxt=res[(i+1)%sz];
			double result=arg((crt-nxt)/(prv-crt));
			if(result<0) result+=2*PI;
			ans[idx[crt]]=result/(2*PI);
		}
	}
	REP(i,n) printf("%.12f\n",ans[i]);

	return 0;
}
