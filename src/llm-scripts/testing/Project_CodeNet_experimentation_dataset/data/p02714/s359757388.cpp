#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define MOD 1000000007

void solve() {
    string s;
    ll n, ans;
    cin >> n >> s;
    vi r, g;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R')
            r.push_back(i);
        else if (s[i] == 'G')
            g.push_back(i);
    }
    ans = (ll)r.size() * (ll)g.size() * (n - (ll)r.size() - (ll)g.size());
    for (auto &i : r) {
        for (auto &j : g) {
            int k1 = 2 * i - j, k2 = 2 * j - i, k3 = (i + j) / 2;
            if (k1 >= 0 && k1 < n && s[k1] == 'B')
                --ans;
            if (k2 >= 0 && k2 < n && s[k2] == 'B')
                --ans;
            if ((i + j) % 2 == 0 && s[k3] == 'B')
                --ans;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
