#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define Rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;
typedef long long int  ll;
typedef pair<int, int> P;

//cout << fixed << setprecision(10);//
//最小公倍数//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//べき//
ll squ(ll n, ll p, ll m){
	if(p==0) return 1;
	if(p%2==0){
		ll t=squ(n, p/2, m);
		return t*t%m;
	}
	return n*squ(n,p-1,m);
	
}


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
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//nが大

ll com(ll n,ll m){
    if(n<m || n<=0 ||m<0){
		return 0;
	}
	if( m==0 || n==m){
		return 1;
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

ll a[100005];

int judge(int n){
	ll y;
ll b[100005];
ll ch=0;


for(int i=1;i<=n;i++){
	if(i==1){y=a[1];
	if(y%2){y--;
	ch=1;
	}
	}
else{
	if(a[i]%2){
		ch++;
		y=gcd(y,a[i]-1);
	}
	else{
		y=gcd(y,a[i]);
	}

}

if(a[i]==1){return 0;}
if(ch>=2){return 0;}

}


if(ch==0){return 0;}
if(y==1||y%2==1){return 0;}
ll sum=0;
for(int i=1;i<=n;i++){
	if(a[i]%2==0){
	b[i]=a[i]/y;}
	else{
		b[i]=(a[i]-1)/y;
	}
if((a[i]-b[i])%2)sum++;
}
if(sum%2){return 0;}
for(int i=1;i<=n;i++){
	a[i]=b[i];
}

return 1;

}






int main() {
ll n;
cin>>n;

ll sum=0;
rep(i, n){
	cin>>a[i];
	sum+=a[i];
}

if(n%2==0){
	if(sum%2==0){
		cout<<"Second"<<endl;
	}
	else{
		cout<<"First"<<endl;
	}
	return 0;
}

if(sum%2==0){cout<<"First"<<endl;
return 0;}

ll inv=0;
for(int u=1;u<=50;u++){
if(judge(n)==1){
	inv++;
}
else{
	break;
}
}



if(inv%2){cout<<"First"<<endl;}
else{cout<<"Second"<<endl;}
return 0;



}



