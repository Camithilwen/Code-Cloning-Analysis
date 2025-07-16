#include<cstdio>
#include<algorithm>
using namespace std;
long long Mod = 998244353, F[10100], InvF[10100], po[10100];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	if (a >= b&&b >= 0)return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
	return 0;
}
long long Get(int a, int b) {
	return Comb(a + b - 1, b);
}
long long Go(int n, int p, int c) {
	if (n == 0)return 1;
	int i;
	long long r = 0;
	for (i = 0; i <= p; i++) {
		if (n < i)continue;
		r = (r + Get(i + c, n - i) * Comb(p,i)%Mod * po[i]) % Mod;
	}
	return r;
}
int main() {
	int i, n, K;
	scanf("%d%d", &K,&n);
	F[0] = InvF[0] =po[0] = 1;
	for (i = 1; i <= 10000; i++) {
		F[i] = F[i - 1] * i%Mod;
		InvF[i] = Pow(F[i], Mod - 2);
		po[i] = po[i - 1] * 2 % Mod;
	}
	for (i = 2; i <= K + K; i++) {
		if (i % 2 == 0) {
			long long t = min(i - 1, K + K + 1 - i);
			printf("%lld\n",(Go(n, t / 2, K - t) + Go(n - 1, t / 2, K - t)) % Mod);
		}
		else {
			long long t = min(i - 1, K + K + 1 - i);
			printf("%lld\n",Go(n, t / 2, K - t));
		}
	}

}