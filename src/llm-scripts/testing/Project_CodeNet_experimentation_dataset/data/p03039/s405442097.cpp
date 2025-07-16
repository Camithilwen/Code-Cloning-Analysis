#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//cout << fixed << setprecision(10);//
//最小公倍数//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//逆元mod(mを法とするaの逆元)//
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

//Cmonp//
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//nが大

ll com(ll n,ll m){
	if(n<=0 || m<=0 || n==m){
		return 1;
	}
	if(n<m){
		return 0;
	}
	ll k=1;
	for(ll i=1;i<=m;i++){
       k*=(n-i+1); 
	   k%=MOD;
	   k*=modinv(i,MOD);
	   k%=MOD;
	}

	return k;
}


////////////////////////////////////////////////////////////////////




int main() {
ll n,m,k;
cin>>n>>m>>k;



ll ml=com(n*m-2,k-2);

ll ans=0;
for(int i=1;i<=n-1;i++){
	ans+=i*m*m*(n-i);
	ans%=MOD;
}

for(int i=1;i<=m-1;i++){
	ans+=i*n*n*(m-i);
	ans%=MOD;
}

ans*=ml;
ans%=MOD;
cout<<ans<<endl;

return 0;

}
