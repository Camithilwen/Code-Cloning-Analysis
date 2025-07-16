#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N, M;
int A[MAXN];

int main() {
	register int i, j = 0, k = 0;
	scanf("%d%d", &N, &M);
	for(i = 1; i <= M; ++i)
		scanf("%d", A + i);
	if(M == 1) {
		if(A[1] == 1) return printf("1\n1\n1\n"), 0;
		printf("%d\n", A[1]);
		printf("%d\n", 2);
		printf("%d %d\n", A[1] - 1, 1);
		return 0;
	}
	for(i = 1; i <= M; ++i)
		if(A[i] & 1) {
			if(!j) j = i;
			else if(!k) k = i;
			else return puts("Impossible"), 0;
		}
	if(j) swap(A[j], A[1]);
	if(k) swap(A[k], A[M]);
	if(j && k && A[1] < A[M]) swap(A[1], A[M]);
	for(i = 1; i <= M; ++i)
		printf("%d%c", A[i], " \n"[i == M]);
	++A[1], --A[M];
	if(!A[M]) --M;
	printf("%d\n", M);
	for(i = 1; i <= M; ++i)
		printf("%d%c", A[i], " \n"[i == M]);
	return 0;
}