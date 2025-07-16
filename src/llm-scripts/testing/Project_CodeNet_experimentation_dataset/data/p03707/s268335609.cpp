#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 2e3 + 5;

char readch() {
    char ch = getchar();
    while (ch != '1' && ch != '0') ch = getchar();
    return ch;
}
int s[maxn][maxn], n, m;
int sn[maxn][maxn], sve[maxn][maxn], she[maxn][maxn];

inline int Sum(int s[][maxn], int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}

int main() {
    int T; scanf("%d%d%d", &n, &m, &T);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch = readch();
            if (ch == '1') s[i][j] = 1;
            else s[i][j] = 0;
        }
    //calc sn, sve, she
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            sn[i][j] = sn[i-1][j] + sn[i][j-1] - sn[i-1][j-1] + s[i][j];
            sve[i][j] = sve[i-1][j] + sve[i][j-1] - sve[i-1][j-1] + (s[i][j] && s[i+1][j]);
            she[i][j] = she[i-1][j] + she[i][j-1] - she[i-1][j-1] + (s[i][j] && s[i][j+1]);
        }
    while (T--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", Sum(sn, x1, y1, x2, y2) - Sum(sve, x1, y1, x2-1, y2) - Sum(she, x1, y1, x2, y2-1));
    }
    return 0;
}