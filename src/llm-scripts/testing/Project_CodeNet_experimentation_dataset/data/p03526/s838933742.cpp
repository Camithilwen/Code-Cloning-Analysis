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

int N;

struct Data {
    int h, p;
    bool operator<(const Data &o) const {
	return min(h, o.h-p) > min(o.h, h-o.p);
    }
} D[5011];

LL X[5011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &D[i].h, &D[i].p);
    sort(D, D+N);

    memset(X, 0x3f, sizeof X);
    LL INF = X[0];
    X[0] = 0;
    REP (i, N) {
	for (int j=i; j>=0; j--) {
	    if (X[j] <= D[i].h) {
		amin(X[j+1], X[j] + D[i].p);
	    }
	}
    }
    int ans = 0;
    REP (i, N+1) if (X[i] < INF) ans = i;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

