#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;

    int count[n + 1];
    // i文字目までにWがいくつあるか(1-indexed)

    // 累積和テーブル
    count[0] = 0;
    rep(i, n) {
        // その地点までの累積和だから前のcount[i]を代入してる
        count[i + 1] = count[i];
        // もしwなら加算
        if (s[i] == 'W') ++count[i + 1];
    }

    int ans = n;
    for (int i = 1; i <= n; ++i) {
        // 自分より西にいて西を向いている人が
        //  count[i-1]人
        // 自分より東にいて東を向いている人が
        //  (n-i)-(count[n]-count[i])人
        ans = min(ans, count[i - 1] + (n - i) - (count[n] - count[i]));
    }

    printf("%d\n", ans);
}