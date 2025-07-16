#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;
int p[MAXN], pn;
bool np[MAXN];

inline void init(int n) {
	register int i, j;
	np[1] = 1; p[0] = p[n] = 1;
	for(i = 2; i <= n; ++i) {
		if(!np[i])
			p[++pn] = i;
		for(j = 1; j <= pn && i * p[j] <= n; ++j) {
			np[i * p[j]] = 1;
			if(i % p[j] == 0)
				break;
		}
	}
}

int main() {
	register int i, j; init(1e4);
	scanf("%d", &N);
	for(i = 0; i < N; ++i) {
		for(j = 0; j < N; ++j) {
			int s = (i + j) >> 1, d = (i - j) >> 1;
			if((i ^ j) & 1) printf("%lld ", 1ll * p[s + 1] * p[d + N + (N >> 1) + 1]);
			else printf("%lld ", 1ll * p[s + 1] * p[s] * p[d + N + (N >> 1) + 1] * p[d + N + (N >> 1)] + 1);
		}
		puts("");
	}
	return 0;
}