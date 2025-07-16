#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll stoi9(string s) {
    // 10 ^ 9倍した整数を返す
    int digit = 0;
    for (int i = sz(s)-1; i >= 0; i--) {
        if (s[i] == '.') {
            s.replace(i, 1, "");
            break;
        }
        digit++;
        if (i == 0) digit = 0;
    }
    ll x = stoll(s);
    rep(i, 9-digit) x *= 10;
    return x;
}

int table[20][20];
ll cum[20][20];

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    rep(i, N) {
        string S;
        cin >> S;
        ll x = stoi9(S);
        int two = 0, five = 0; // 2と5で何回割れるか
        while (x%2 == 0 && two < 18) {
            two++;
            x /= 2;
        }
        while (x%5 == 0 && five < 18) {
            five++;
            x /= 5;
        }
        table[two][five]++;
        if (two >= 9 && five >= 9) ans--;
    }
    for (int i = 18; i >= 0; i--) {
        for (int j = 18; j >= 0; j--) {
            cum[i][j] = table[i][j] + cum[i+1][j] + cum[i][j+1] - cum[i+1][j+1];
        }
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            ans += table[i][j] * cum[18-i][18-j];
        }
    }
    ans /= 2;
    cout << ans << '\n';
    return 0;
}
