#include <iostream>
using namespace std;

#define INF 10000000

// 0: cost , 1 :time
int d[2][101][101];


int main() {
    int n, m, a, b, cost, time, k, p, q, r, i, j;

    while ((cin >> n >> m) && n) {
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= m; j++) {
                d[0][i][j] = d[1][j][i] = INF;
            }
        }
        for (i = 0; i < n; i++) {
            cin >> a >> b >> cost >> time;
            d[0][a][b] = d[0][b][a] = cost;
            d[1][a][b] = d[1][b][a] = time;
        }

        for (k = 1; k <= m; k++) {
            for (i = 1; i <= m; i++) {
                for (j = 1; j <= m; j++) {
                    for (r = 0; r < 2; r++) {
                        if (d[r][i][j] > d[r][i][k] + d[r][k][j]) {
                            d[r][j][i] = d[r][i][j] = d[r][i][k] + d[r][k][j];
                        }
                    }
                }
            }
        }

        cin >> k;
        while (k--) {
            cin >> p >> q >> r;
            cout << d[r][p][q] << endl;
        }
    }
    
    return 0;
}