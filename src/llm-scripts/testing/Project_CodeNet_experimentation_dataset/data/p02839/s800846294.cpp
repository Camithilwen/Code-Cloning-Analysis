#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "Yes" : "No")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 80 + 1;
const int SIZ = 2 * 6400 + 1;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "1";

int a[siz][siz];
bool f[siz][siz][SIZ];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            a[i][j] = abs(a[i][j] - x);
        }
    }

    f[1][1][a[1][1]] = true;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < SIZ; k++) {
                if (f[i][j][k] == true) {
                    if (i < m) {
                        f[i + 1][j][abs(k - a[i + 1][j])] = true;
                        f[i + 1][j][k + a[i + 1][j]] = true;
                    }

                    if (j < n) {
                        f[i][j + 1][abs(k - a[i][j + 1])] = true;
                        f[i][j + 1][k + a[i][j + 1]] = true;
                    }
                }
            }
        }
    }

    for (int k = 0; k < SIZ; k++) {
        if (f[m][n][k] == true) {
            return cout << k << "\n", 0;
        }
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
