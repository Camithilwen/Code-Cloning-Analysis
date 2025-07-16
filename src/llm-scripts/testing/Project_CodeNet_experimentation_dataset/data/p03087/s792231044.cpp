#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' +  s; // 文字列を1オリジンで考える
    n++;
    vector<int> dp(n); // sの先頭からi文字目(1<=i<=n)までに含まれるACの数を記録する配列
    rep(i, n) {
        if (i == 0 || i == 1) dp[i] == 0;
        else if (s[i-1] == 'A' && s[i] == 'C') dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
        // cout << dp[i] << " ";
    }
    cout << endl;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        // int cnt = 0;
        // for (int i = l; i <= r - 1; i++) {
        //     if (s[i] == 'A' && s[i+1] == 'C') cnt++;
        // }
        // cout << cnt << endl;
        cout << dp[r] - dp[l] << endl;
    }
}