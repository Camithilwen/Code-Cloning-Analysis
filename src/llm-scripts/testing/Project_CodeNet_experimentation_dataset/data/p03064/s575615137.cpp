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

inline int fastpow(int bas, int ex){
	register int res = 1;
	for(; ex; ex >>= 1, bas = bas * (ll)bas % MOD) if(ex & 1) res = res * (ll)bas % MOD;
	return res;
}

inline int kazu(int a, const int &b) {return (a += b) >= MOD ? a - MOD : a;}
inline int hiku(int a, const int &b) {return (a -= b) < 0 ? a + MOD : a;}

int N, sum = 0, f[90005], g[90005];

int main(){
	getint(N), f[0] = g[0] = 1; 
	for(register int i = 1, a; i <= N; i++){
		getint(a), sum += a;
		for(register int j = sum; j >= 0; j--){
			f[j] = f[j] * 2LL % MOD;
			if(j >= a) f[j] = kazu(f[j], f[j - a]), g[j] = kazu(g[j], g[j - a]);
		}
	}
	int ans = fastpow(3, N);
	for(register int i = sum + 1 >> 1; i <= sum; i++) ans = hiku(ans, f[i] * 3LL % MOD);
	if(!(sum & 1)) ans = kazu(ans, g[sum >> 1] * 3LL % MOD);
	return printf("%d\n", ans), 0;
}