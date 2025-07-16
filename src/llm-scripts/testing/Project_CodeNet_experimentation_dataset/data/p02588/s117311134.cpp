#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> c(20, vector<int>(20));
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll x = 0;
        bool found = false;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '.') (x *= 10) += s[i] - '0';
            else found = true;
        }
        if (!found)  x *= (ll)1e9;
        else {
            int cur = 0;
            while (s.back() != '.')
                ++cur,s.pop_back();
            for (int it = 0; it < 9 - cur; it++) x *= 10;
        }
        int c2=0,c5=0;
        ll y = x;
        while (y % 2 == 0)
            ++c2,y /= 2;
        y = x;
        while (y % 5 == 0)
            ++c5,y /= 5;
        ++c[min(18, c2)][min(18, c5)];
        a.emplace_back(min(18, c2), min(18, c5));
    }
    for (int i = 18; i >= 0; i--)
        for (int j = 18; j >= 0; j--)
            c[i][j] += c[i + 1][j] + c[i][j + 1] - c[i + 1][j + 1];
    ll w = 0;
    for (auto x : a)
        w += c[18 - x.first][18 - x.second] - (x.first >= 9 && x.second >= 9);
    w /= 2;
    cout << w;
    return 0;
}