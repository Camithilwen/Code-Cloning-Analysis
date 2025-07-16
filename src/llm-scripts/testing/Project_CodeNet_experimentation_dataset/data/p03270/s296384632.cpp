#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define MOD 998244353
#define int ll

int N,K;

int fac[5001];


int exp(int a,int b){
	int res = 1;
	
	while (b > 0){
		if (b&1){
			res *= a;
			res %= MOD;
		}
		
		b >>= 1;
		a *= a;
		a %= MOD;
	}
	return res;
}

int modinv(int A,int B){
	A %= MOD;
	B = exp(B,MOD-2);
	A *= B;
	A %= MOD;
	return A;
}

int nchoosek(int n,int k){
	if (n < k) return 0;
	return modinv(fac[n],(fac[k] * fac[n-k]) % MOD);
}
			
int32_t main(){
	fast;
	
	cin>>K>>N;
	
	
	
	
	fac[0] = 1;
	FOR(i,1,4999){
		fac[i] = (fac[i-1] * i) % MOD;
	}
	int num = nchoosek(N + K - 1,N);
	
	//cout<<num<<'\n';
	FOR(k,2,2*K){
		int pairs = 0;
		FOR(i,1,K){
			if (1 <= k - i && k-i <= K) pairs++;
		}
		if (k % 2 == 0) pairs++;
		pairs /= 2;
		
		//cout<<pairs<<'\n';
		
		int ans = num;
		FOR(i,1,pairs){
			int val = (nchoosek(N - i * 2 + K - 1,N - i * 2) * nchoosek(pairs,i)) % MOD;
			if (i % 2 == 0) ans = (ans + val) % MOD;
			else ans = (ans - val + MOD)%MOD;
		}
		
		cout<<ans<<'\n';
	}
		
}

