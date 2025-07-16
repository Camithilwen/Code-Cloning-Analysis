#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()

const int maxn = 5e5 + 1;

using namespace std;

int n;
string s;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    bitset<26> bt;
    if (n < 26) {
        for (int i = 0; i < n; i++)
            bt[s[i] - 'a'] = 1;
        cout << s;
        for (int x = 0; x < 26; x++)
            if (!bt[x]) {
                cout << (char)(x + 'a');
                break;
            }
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        bool fg = 0;
        for (char j = s[i] + 1; j <= 'z'; j++) {
            fg = 1;
            for (int l = 0; l < i; l++) {
                if (s[l] == j) {
                    fg = 0;
                    break;
                }
            }
            if (!fg) continue;
            s[i] = j;
            cout << s.substr(0, i + 1);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
