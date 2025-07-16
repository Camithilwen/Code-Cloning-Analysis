#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using i64 = long long;
using f64 = double;
using pll = pair<i64, i64>;
using pii = pair<int, int>;
using ptx = pair<f64, f64>;

i64 mp[256];

int main() {
#ifdef HOME
    freopen("agc019b.in", "r", stdin);
    freopen("agc019b.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;
    for (auto i: str)
        mp[i]+= 1;

    i64 ans = str.size() * (str.size() - 1) / 2;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        ans-= mp[ch] * (mp[ch] - 1) / 2;

    cout << 1 + ans << endl;

    return 0;
}
