#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N, M;
int A[MAXN];
int cnt;

int main() {
	register int i, j = 0, k = 0;
	scanf("%d%d", &N, &M);
	for(i = 1; i <= M; ++i)
		scanf("%d", A + i),
		A[i] & 1 ? (++cnt, !j ? j = i : k = i) : 0;
	if(cnt > 2) return puts("Impossible"), 0;
	if(M == 1) {
		printf("%d\n", A[1]);
		printf("%d\n", A[1] == 1 ? 1 : 2);
		A[1] == 1 ? printf("%d\n", A[1]) : printf("1 %d\n", A[1] - 1);
		return 0;
	}
	if(j) swap(A[1], A[j]); if(k) swap(A[k], A[M]);
	for(i = 1; i <= M; ++i)
		printf("%d%c", A[i], " \n"[i == M]);
	++A[1], --A[M];
	if(A[M] == 0) --M;
	printf("%d\n", M);
	for(i = 1; i <= M; ++i)
		printf("%d%c", A[i], " \n"[i == M]);
	return 0;
}