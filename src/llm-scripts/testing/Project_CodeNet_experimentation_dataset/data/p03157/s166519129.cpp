#include<cstdio>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char s[400][401];
int par[160000];
int c1[160000];
int c2[160000];
int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[x] = y;
}
int main() {
    int h, w, i, j, k;
    long long ans = 0;
    scanf("%d %d", &h, &w);
    for (i = 0; i < h; i++) scanf("%s", s[i]);
    for (i = 0; i < h * w; i++) par[i] = i;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            for (k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= h || y < 0 || y >= w) continue;
                if (s[i][j] != s[x][y]) unite(i * w + j, x * w + y);
            }
        }
    }
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                c1[find(i * w + j)]++;
            } else {
                c2[find(i * w + j)]++;
            }
        }
    }
    for (i = 0; i < h * w; i++) ans += (long long)c1[i] * c2[i];
    printf("%lld\n", ans);
    return 0;
}
