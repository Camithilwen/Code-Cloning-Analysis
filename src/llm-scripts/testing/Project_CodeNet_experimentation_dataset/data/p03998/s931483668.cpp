#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s[3];
    rep(i, 3) cin >> s[i];

    int t = 0;
    vector<int> idx(3);
    while (true) {
        if (s[t].size() == idx[t]) {
            cout << char('A' + t) << endl;
            return 0;
        }
        t = s[t][idx[t]++] - 'a';
    }

    return 0;
}
