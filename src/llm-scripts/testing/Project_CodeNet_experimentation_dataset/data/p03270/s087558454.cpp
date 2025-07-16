#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MOD 998244353
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

inline int tasu(int a, const int &b) {return (a += b) >= MOD ? a - MOD : a;}

inline ll fastpow(ll bas, ll ex){
	register ll res = 1; bas %= MOD;
	for(; ex; ex >>= 1, bas = bas * bas % MOD) if(ex & 1) res = res * bas % MOD;
	return res;
}

int K, N;
ll p2[4005] = {1}, fac[4005] = {1}, ifac[4005];

inline ll binom(const int &n, const int &m) {return n < m || m < 0 ? 0 : fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;}

inline int calc(const int &x, const int &y, const int &n){  // x pairs of conflict numbers, y free numbers, n sides of dices
	register int res = 0;
	for(register int i = 0, lim = min(x, n); i <= lim; i++)
		res = tasu(res, binom(x, i) * p2[i] % MOD * binom(n + y - 1, i + y - 1) % MOD);
	return res;
}

int main(){
	getint(K), getint(N);
	for(register int i = 1; i <= N + K; i++) fac[i] = fac[i - 1] * i % MOD, p2[i] = (p2[i - 1] << 1) % MOD;
	ifac[N + K] = fastpow(fac[N + K], MOD - 2);
	for(register int i = N + K; i >= 1; i--) ifac[i - 1] = ifac[i] * i % MOD;
	for(register int i = 2; i <= (K << 1); i++){
		const int cnt = min(i, (K + 1 << 1) - i) - 1 >> 1;
		if(i & 1) printf("%d\n", calc(cnt, K - (cnt << 1), N));
		else printf("%d\n", tasu(calc(cnt, K - (cnt << 1) - 1, N), calc(cnt, K - (cnt << 1) - 1, N - 1)));
	}
	return 0;
}