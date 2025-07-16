
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)

const int mod = 998244353;
const int mxn = 1e5;
int n,K;

void add(ll &a, ll b) { if (b>=mod) b%=mod; a+=b; if (a>=mod) a-=mod; }
ll modpow(ll a, ll b) {
	return b?modpow(a*a%mod,b/2)*(b&1?a:1)%mod:1;
}
struct Comb {
	ll fac[mxn], inv[mxn], twopow[mxn];	
	Comb() {
		f(i,0,mxn) {
			fac[i]=i?fac[i-1]*i%mod:1;
			twopow[i]=i?twopow[i-1]*2%mod:1;
		}
		inv[mxn-1]=modpow(fac[mxn-1],mod-2);
		fr(i,0,mxn-1) {
			inv[i]=inv[i+1]*(i+1)%mod;
		}
	}
	ll choose(int n, int r) {
		if (n<0||n<r||r<0) return 0;
		return fac[n]*inv[r]%mod*inv[n-r]%mod;
	}
	ll multichoose(int n, int k) {
		if (!n&&!k) return 1;
		return choose(n+k-1,k);
	}
	ll pow2(int n) {
		if (n<0) return 0;
		return twopow[n];
	}
} C;

ll solve(int x) {
	ll ans = 0;
	int a = 0, b = 0;
	f(i,1,K+1) {
		if (i+i==x) b++;
		if (i<=K && x-i<=K && x-i>0) a++;
	}
	a/=2;
	f(na,0,a+1) {
		f(nb,0,b+1) {
			add(ans,C.pow2(na)*C.choose(a,na)%mod*C.multichoose(na+K-2*a-b,n-na-nb));		
		}
	}
	return ans;
}

const int DEBUG = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	if (DEBUG) freopen("input.txt", "r", stdin);
	if (DEBUG) freopen("output.txt", "w", stdout);
#endif

	cin >> K >> n;
	for (int x = 2; x <= 2*K; x++)
		cout << solve(x) << endl;
	cout << endl;

	return 0;
}

