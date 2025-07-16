#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int const MAXN=2.2e6;
int const MD=998244353;

int madd(int x,int y) {
	if (x+y<MD) return x+y; else return x+y-MD;
}
int msub(int x,int y) {
	if (x-y>=0) return x-y; else return x-y+MD;
}
int mmul(int x,int y) {
	return int(ll(x)*y % MD);
}
int mpow(int x,int p) {
	int res=1;
	while (p>0) {
		if (p%2) res=mmul(res,x);
		x=mmul(x,x);
		p/=2;
	}
	return res;
}
int minv(int x) {
	return mpow(x,MD-2);
}
int mdiv(int x,int y) {
	return mmul(x,mpow(y,MD-2));
}

struct mod_fact {
	vector<int> f,rf;
	mod_fact(int n):f(n),rf(n) {
		f[0]=rf[0]=1;
		rep(i,1,n) {
			f[i]=mmul(f[i-1],i);
			rf[i]=minv(f[i]);
		}
	}
} mfact(MAXN);

int comb(int n,int k) {
	if (n<k) return 0;
	return mmul(mfact.f[n],mmul(mfact.rf[n-k],mfact.rf[k]));
}
int distr(int n,int k) {
	return comb(n+k-1,k-1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	int N,M;
	cin>>N>>M;
	
	int res=0;
	rep(i,0,min(N,M)+1) if ((3*M-i)%2==0) {
		int add=mmul(comb(N,i),distr((3*M-i)/2,N));
		res=madd(res,add);
	}
	rep(i,0,min(N,M)+1) if ((M-i)%2==0) {
		int sub=mmul(comb(N,i),distr((M-i)/2,N));
		res=msub(res,mmul(sub,N));
	}
	rep(i,0,min(N,M)+1) if ((M-i)%2==0) {
		int add=mmul(comb(N-1,i),distr((M-i)/2,N-1));
		res=madd(res,mmul(add,N));
	}
	cout<<res<<'\n';
}
