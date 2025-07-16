#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


int H, W;
char F[111][111];

int A[101][101];
short dp[101][101][101][101];
short box(int l, int u, int r, int d) {
    return A[d][r] - A[d][l] - A[u][r] + A[u][l];
}

int main() {
    scanf("%d%d", &H, &W);
    REP (i, H) scanf("%s", F[i]);

    int si, sj;

    REP (i, H) REP (j, W) {
	if (F[i][j] == 'E') {
	    si = i;
	    sj = j;
	}
	A[i+1][j+1] = A[i][j+1] + A[i+1][j] - A[i][j];
	if (F[i][j] == 'o') A[i+1][j+1] ++;
    }


    int ans = 0;
    REP (l, sj+1) REP (r, W-sj) REP (u, si+1) REP (d, H-si) {
	short cur = dp[l][r][u][d];
	amax(ans, (int)cur);

	int R, L, D, U;

	U = max(si-u, d); D = min(si+d+1, H-u);
	if (sj-1-l >= r && U < D) amax<short>(dp[l+1][r][u][d], cur + box(sj-1-l, U, sj-l, D));
	if (sj+1+r < W-l && U < D) amax<short>(dp[l][r+1][u][d], cur + box(sj+1+r, U, sj+2+r, D));

	L = max(sj-l, r); R = min(sj+r+1, W-l);
	if (si-1-u >= d && L < R) amax<short>(dp[l][r][u+1][d], cur + box(L, si-1-u, R, si-u));
	if (si+1+d < H-u && L < R) amax<short>(dp[l][r][u][d+1], cur + box(L, si+1+d, R, si+2+d));
    }

    printf("%d\n", ans);



    return 0;
}

