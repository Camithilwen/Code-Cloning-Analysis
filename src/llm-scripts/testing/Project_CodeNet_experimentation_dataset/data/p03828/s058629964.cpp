#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
#define int long long
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
    int n;
    cin >> n;
    map<int, int> mp;
    rep (i, 1, n + 1) {
        int k = i;
        for (int j = 2; j * j <= k; j++) {
            while (k % j == 0) {
                k /= j;
                mp[j]++;
            }
        }
        mp[k]++;
    }
    int ans = 1;
    const int mod = 1e9 + 7;
    for (auto p : mp) {
        // cout << p.first << " : " << p.second << "\n";
        if (p.first == 1) continue;
        ans = ans * (p.second + 1) % mod;
        // cout << ans << "\n";
    }
    cout << ans << "\n";
}