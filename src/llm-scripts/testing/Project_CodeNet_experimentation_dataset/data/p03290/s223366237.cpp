#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int d, g;
    cin >> d >> g;
    int p[d], c[d];
    rep (i, 0, d) cin >> p[i] >> c[i];
    // 全完するものをbitで表す
    int ans = inf;
    rep (bit, 0, 1 << d) {
        int sum = 0, cnt = 0;
        rep (i, 0, d) {
            if (bit & 1 << i) {
                sum += (i + 1) * 100 * p[i] + c[i];
                cnt += p[i];
            }
        }
        if (sum >= g) {
            ans = min (ans, cnt);
        } else {
            per (i, 0, d) {
                if (1 << i & bit) continue;
                int res = (g - sum) / (100 * (i + 1));
                if (res * 100 * (i + 1) + sum < g) res++;
                if (res > p[i]) break;
                cnt += res;
                sum += res * 100 * (i + 1);
                break;
            }
            if (sum >= g) ans = min (ans, cnt);
        }
    }
    cout << ans << "\n";
}