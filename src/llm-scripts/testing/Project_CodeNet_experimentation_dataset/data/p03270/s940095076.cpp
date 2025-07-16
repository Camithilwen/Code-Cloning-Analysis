#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()
const int maxn = 6010;
const int mod = 998244353;


int fac[maxn];
map <int,int> mp;


int expo(int x, int exp) {
	int res = 1, base = x;
	while (exp) {
		if (exp & 1) res = (res * base) % mod;
		base = (base*base) % mod;
		exp >>= 1;
	}
	return res;
}

int inv(int x) {
	if (mp.find(x) != mp.end()) return mp[x];
	else return mp[x] = expo(x,mod-2);
}


int choose(int N, int k) {
	return fac[N] * inv(fac[k]*fac[N - k] % mod) % mod;
}

int K,n;

int32_t main() {
	FAST
	cin >> K >> n;
	fac[0] = 1;
	for (int i =1; i<maxn;i++) fac[i] = fac[i-1] * i % mod;
	
	for (int i = 2;i <= 2 * K; i++) {
		int ans = 0;
		int pairs = i/2 - max(1ll, i - K) + 1;
		
		for (int x = 0; x <= pairs; x++) {
			if (n < x * 2) break;
			int v = choose(n - x*2 + K -1, n - x * 2) * choose(pairs,x) % mod;
			if (x % 2 == 0) ans = (ans + v) % mod; 
			else ans = (ans - v + mod) % mod;
			//cout << i << " " << x << " " << v << " " << ans << "\n";
		}
		cout << ans << "\n";
	}
}







