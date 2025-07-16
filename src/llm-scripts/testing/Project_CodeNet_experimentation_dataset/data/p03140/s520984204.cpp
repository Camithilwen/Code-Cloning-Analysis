#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    string s[3];
    rep(i, 3) cin >> s[i];

    int ans = 0;
    rep(i, n) {
        set<char> st;
        rep(j, 3) st.insert(s[j][i]);
        ans += st.size() - 1;
    }

    cout << ans << endl;

    return 0;
}