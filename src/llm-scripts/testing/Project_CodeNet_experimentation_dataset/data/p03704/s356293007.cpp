#include <cstdio>

#define F(i, a, b) for (LL i = a; i <= b; i ++)
#define G(i, a, b) for (LL i = a; i >= b; i --)
#define pf printf

typedef long long LL;

const LL N = 1e7 + 10;
const LL M = 20;

using namespace std;

LL D, L, Ans, Sum, total, w[M];
LL ten[M], v[M], tot[M], TOT[M];

void Dfs(LL k, LL s, LL S) {
	if (s < 0) return;
	if (s + 10 * v[k] < D) return;
	if (s - 10 * v[k] > D) return;
	if (k > L) {
		if (s == D) {
			Sum += S;
//			printf("Yes\n");
		}
		return;
	}
	F(i, -9, 9)
		w[k] = i, Dfs(k + 1, s + v[k] * i, S * (k == 1 ? TOT[i + 9] : tot[i + 9]));
}

int main() {
	scanf("%lld", &D);
//	F(i, 1, N - 10) {
//		LL rev = 0;
//		for (LL x = i; x; rev = rev * 10 + (x % 10), x /= 10);
//		if (rev - i == D)
//			printf("%lld\n", i), total ++;
//	}

//	puts("");

	F(i, 0, 9)
		F(j, 0, 9)
			tot[i - j + 9] ++;
	F(i, 0, 9)
		F(j, 1, 9)
			TOT[i - j + 9] ++;

	ten[0] = 1;
	F(i, 1, 18)
		ten[i] = ten[i - 1] * 10LL;
	F(i, 2, 18) {
		L = i / 2, Sum = 0;
		F(j, 1, L)
			v[j] = ten[i - j] - ten[j - 1];
		Dfs(1, 0, 1);
		Ans += Sum * ((i & 1) ? 10 : 1);
//		pf("%d\n", i);
	}
	pf("%lld\n", Ans);
}