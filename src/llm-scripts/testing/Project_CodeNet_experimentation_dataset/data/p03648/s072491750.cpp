#include <cstdio>
using namespace std;

typedef long long LL;
const int N = 55;
int n; LL K, a[N];

template <class T> inline void in(T &x) {
	x = 0; int f = 1; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + (LL)ch-'0', ch = getchar();
	x *= f;
}

inline void work() {
	in(K), n = 50; LL tmp = K / n;
	for (int i = 1; i <= n; ++i) a[i] = n - 1;
	for (int i = 1; i <= n; ++i) a[i] += tmp;
	for (int i = 1; i <= K % n; ++i) {
		a[i] += n;
		for (int j = 1; j <= n; ++j) if (i != j) --a[j];
	}
	int lim = K % n;
	printf("%d\n", n);
	for (int i = 1; i < n; ++i) printf("%lld ", a[i]);
	printf("%lld\n", a[n]);
}

int main() {work(); return 0;}