#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int H, W, f[maxn][maxn], pre[maxn], suf[maxn];
char s[maxn][maxn];
bool chk[maxn][maxn];

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= W; j++) {
            if (i > 1 && j > 1) {
                int cnt = (s[i][j] == '.') + (s[i - 1][j] == '.') +
                    (s[i][j - 1] == '.') + (s[i - 1][j - 1] == '.');
                if (cnt & 1) chk[i - 1][j - 1] = 1;
            }
        }
    }
    H--, W--;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            f[i][j] = chk[i][j] ? 0 : (f[i - 1][j] + 1);
        }
    }
    int ans = max(H + 1, W + 1);
    for (int i = 1; i <= H; i++) {
        stack<int> st;
        f[i][0] = f[i][W + 1] = -1;
        st.push(0);
        for (int j = 1; j <= W; j++) {
            while (f[i][st.top()] >= f[i][j]) st.pop();
            pre[j] = st.top(), st.push(j);
        }
        while (!st.empty()) st.pop();
        st.push(W + 1);
        for (int j = W; j; j--) {
            while (f[i][st.top()] >= f[i][j]) st.pop();
            suf[j] = st.top(), st.push(j);
        }
        for (int j = 1; j <= W; j++) {
            ans = max(ans, (f[i][j] + 1) * (suf[j] - pre[j]));
        }
    }
    printf("%d\n", ans);
    return 0;
}