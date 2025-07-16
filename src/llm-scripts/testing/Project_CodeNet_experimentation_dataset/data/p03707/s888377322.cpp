#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n, m, q;
char B[Maxn][Maxn];
int sq[Maxn][Maxn];
int edH[Maxn][Maxn], edV[Maxn][Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%s", B[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i + 1 <= n && B[i][j] == '1' && B[i + 1][j] == '1')
                edH[i + 1][j]++;
            if (j + 1 <= m && B[i][j] == '1' && B[i][j + 1] == '1')
                edV[i][j + 1]++;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            sq[i][j] = sq[i - 1][j] + sq[i][j - 1] - sq[i - 1][j - 1] + int(B[i][j] == '1');
            edH[i][j] += edH[i - 1][j] + edH[i][j - 1] - edH[i - 1][j - 1];
            edV[i][j] += edV[i - 1][j] + edV[i][j - 1] - edV[i - 1][j - 1];
        }
    while (q--) {
        int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int V = sq[r2][c2] - sq[r1 - 1][c2] - sq[r2][c1 - 1] + sq[r1 - 1][c1 - 1];
        int E = edH[r2][c2] - edH[r1][c2] - edH[r2][c1 - 1] + edH[r1][c1 - 1] +
                edV[r2][c2] - edV[r1 - 1][c2] - edV[r2][c1] + edV[r1 - 1][c1];
        printf("%d\n", V - E);
    }
    return 0;
}
