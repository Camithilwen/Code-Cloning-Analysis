#include <bits/stdc++.h>

#define int long long

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)a, i##_len=(b); i<i##_len; i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(box) box.begin(), box.end()

using namespace std;

using P = pair<int,int>;
using ll = long long;

const long long INF = LLONG_MAX/3;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind{
	std::vector<int> par,siz;
	void init(int n){
		par.resize(n);
		for(int i=0;i<n;i++)par[i]=i;
		siz.resize(n,1);
	}
	UnionFind(int n){
		init(n);
	}
	int root(int n){
		if(par[n]==n)return n;
		else return par[n]=root(par[n]);
	}
	bool issame(int x,int y){
		return (root(x)==root(y));
	}
	bool marge(int a,int b){
		if(issame(a,b))return false;
		else{
			a=root(a),b=root(b);
			if(siz[a]<siz[b])swap(a,b);
			siz[a]+=siz[b];
			par[a]=par[b];
			return true;
		}
	}
	int size(int n){
		return siz[root(n)];
	}
};

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long i,long long j){
    return i*(j/gcd(i,j));
}

const int MOD=1e9+7;
long long fac[510000], finv[510000], inv[510000];
long long MAX=510000;
bool COMinited=false;
long long COM(int n, int k){
	if(COMinited==false){
		fac[0] = fac[1] = 1;
    	finv[0] = finv[1] = 1;
    	inv[1] = 1;
    	for (int i = 2; i < MAX; i++){
        	fac[i] = fac[i - 1] * i % MOD;
        	inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        	finv[i] = finv[i - 1] * inv[i] % MOD;
    	}
		COMinited=true;
	}
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	int cn=0;
	int cnt=0;
	for(int i=2;i<=n;i++)cnt+=i-1;
	cn+=cnt;
	for(int i=2;i<=n;i++){
		cnt-=n-i+1;
		cnt+=i-1;
		cn+=cnt;
	}
	cn/=2;
	int ans=0;
	ans+=(((m*m)%MOD*cn)%MOD*COM(n*m-2,k-2))%MOD;
	int cm=0;
	cnt=0;
	for(int i=2;i<=m;i++)cnt+=i-1;
	cm+=cnt;
	for(int i=2;i<=m;i++){
		cnt-=m-i+1;
		cnt+=i-1;
		cm+=cnt;
	}
	cm/=2;
	ans+=(((n*n)%MOD*cm)%MOD*COM(n*m-2,k-2))%MOD;
	cout<<ans%MOD<<endl;
}