#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
/*
6
abcdef
aabbdd

abcdef
abbddd
aabbdd

6
abcdef
aabcde

abcdef
abcdee
abcdde
abccde
abbcde
aabcde
*/

int N;
char S[1000111];
char T[1000111];
int C[1000111];
int off = 0, add = 0;

void MAIN() {
    scanf("%d%s%s", &N, S, T);
    while (N > 0 && S[N-1] == T[N-1]) N--;

    memset(C, 0xc0, sizeof C);
    int pos = N-1;
    int ans = 0;
    for (int i=N-1; i>=0; ) {
	int j=i;
	while (j > 0 && T[j-1] == T[i]) j--;

	// T[j .. i];
	int nxt = min(pos, j);
	while (nxt >= 0 && S[nxt] != T[i]) nxt--;
	if (nxt == -1) {
	    puts("-1");
	    return;
	}

	off++;
	add++;
	for (int k=nxt; k<=pos; k++) C[k+off] = 1 - add;
	for (int k=j; k<=i; k++) amax(ans, C[k+off] + add);

//	REP (z, N) eprintf("%d ", C[z+off] + add);
//	eprintf("\n");

	pos = nxt - 1;
	i = j-1;
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

