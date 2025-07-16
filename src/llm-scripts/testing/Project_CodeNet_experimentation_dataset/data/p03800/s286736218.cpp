#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n;
string s;

bool val = false;
bitset<N> ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    int variations[4][2] = {{0, 1}, {0, 0}, {1, 0}, {1, 1}};

    for (int v = 0; v < 4; ++v) {
        ans.reset();
        ans[0] = variations[v][0];
        ans[1] = variations[v][1];

        for (int i = 1; i < n - 1; ++i) {
            if (!ans[i]) {
                if (s[i] == 'o') ans[i + 1] = ans[i - 1];
                else ans[i + 1] = !ans[i - 1];
            } else {
                if (s[i] == 'o') ans[i + 1] = !ans[i - 1];
                else ans[i + 1] = ans[i - 1];
            }
        }

        bool good = true;
        if (ans[n - 1]) {
            if (s[n - 1] == 'o' && ans[n - 2] == ans[0]) {
                good = false;
            } else if (s[n - 1] == 'x' && ans[n - 2] != ans[0]) {
                good = false;
            }
        } else {
            if (s[n - 1] == 'o' && ans[n - 2] != ans[0]) {
                good = false;
            } else if (s[n - 1] == 'x' && ans[n - 2] == ans[0]) {
                good = false;
            }
        }

        if (ans[0]) {
            if (s[0] == 'o' && ans[1] == ans[n - 1]) {
                good = false;
            } else if (s[0] == 'x' && ans[1] != ans[n - 1]) {
                good = false;
            }
        } else {
            if (s[0] == 'o' && ans[1] != ans[n - 1]) {
                good = false;
            } else if (s[0] == 'x' && ans[1] == ans[n - 1]) {
                good = false;
            }
        }

        if (good) {
            val = true;
            break;
        }
    }

    if (!val) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (!ans[i]) cout << 'S';
        else cout << 'W';
    }
}
