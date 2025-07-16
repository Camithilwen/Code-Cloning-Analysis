#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S[N];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int vcnt[N + 1][M + 1];
    fill(vcnt[0], vcnt[N + 1], 0);
    // vcnt[i][j] = (1, 1)~(i, j)中の青マスの数
    // vcnt[i][0] = vcnt[0][j] = 0

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // indexのズレに注意
            vcnt[i + 1][j + 1] = vcnt[i][j + 1] + vcnt[i + 1][j] - vcnt[i][j] + (S[i][j] == '1');
        }
    }

    int ercnt[N + 1][M + 1];
    fill(ercnt[0], ercnt[N + 1], 0);
    // ercnt[i][j] = (1, 1)~(i, j)中での青マスの横連結箇所数(row)

    int eccnt[N + 1][M + 1];
    fill(eccnt[0], ercnt[N + 1], 0);
    // eccnt[i][j] = (1, 1)~(i, j)中での青マスの縦連結箇所数(column)

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ercnt[i + 1][j + 1] = ercnt[i][j + 1] + ercnt[i + 1][j] - ercnt[i][j];
            ercnt[i + 1][j + 1] += (j > 0 && S[i][j] == '1' && S[i][j - 1] == '1');

            eccnt[i + 1][j + 1] = eccnt[i][j + 1] + eccnt[i + 1][j] - eccnt[i][j];
            eccnt[i + 1][j + 1] += (i > 0 && S[i][j] == '1' && S[i - 1][j] == '1');
        }
    }

    for (int q = 0; q < Q; ++q) {
        int x[2], y[2];
        for (int i = 0; i < 2; ++i) {
            cin >> x[i] >> y[i];
        }

        int v = vcnt[x[1]][y[1]] - vcnt[x[0] - 1][y[1]] - vcnt[x[1]][y[0] - 1] + vcnt[x[0] - 1][y[0] - 1];

        int e = 0;
        e += ercnt[x[1]][y[1]] - ercnt[x[1]][y[0]] - ercnt[x[0] - 1][y[1]] + ercnt[x[0] - 1][y[0]];
        e += eccnt[x[1]][y[1]] - eccnt[x[0]][y[1]] - eccnt[x[1]][y[0] - 1] + eccnt[x[0]][y[0] - 1];

        cout << v - e << endl;
    }

    return 0;
}