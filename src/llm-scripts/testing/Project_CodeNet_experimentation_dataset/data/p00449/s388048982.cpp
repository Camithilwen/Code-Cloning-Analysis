#include <cstdio>

using namespace std;

#define min(a,b) (((a) > (b))?(b):(a))
#define INF 1000001

int dp[100][100];
int V;

int warshall_floyd(int k) {
    int i;

    for (i=0;i<V;i++) {
        int j;
        for (j=0;j<V;j++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
}

int main() {
    while (1) {
        int i;
        int n, k;

        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) return 0;

        V = n;
        for (i=0;i<n;i++) {
            int j;
            for (j=0;j<n;j++) {
                if (i == j) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INF;
                }
            }
        }

        for (i=0;i<k;i++) {
            int c, d;
            int query;

            scanf("%d", &query);
            if (query) {
                int e;

                scanf("%d%d%d", &c, &d, &e);
                c--;
                d--;
                if (dp[c][d] > e) dp[c][d] = e;
                if (dp[d][c] > e) dp[d][c] = e;
                warshall_floyd(c);
                warshall_floyd(d);
            } else {
                int c, d;

                scanf("%d%d", &c, &d);
                c--;
                d--;
                if (dp[c][d] == INF) printf("%d\n", -1);
                else printf("%d\n", dp[c][d]);
            }
        }
    }
}