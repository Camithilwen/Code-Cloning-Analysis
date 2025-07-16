#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    while (cin >> n && n) {
        cin >> k;
        int dist[105][105];
        fill_n(*dist, 105 * 105, inf);
        rep(i, 105) dist[i][i] = 0;
        
        while (k--) {
            int q;
            cin >> q;
            if (q == 0) {
                int a, b;
                cin >> a >> b;
                a--; b--;
                if (dist[a][b] != inf) cout << dist[a][b] << endl;
                else cout << -1 << endl;
            } else {
                int c, d, e;
                cin >> c >> d >> e;
                c--; d--;
                chmin(dist[c][d], e);
                chmin(dist[d][c], e);
                rep(k, n) rep(i, n) rep(j, n) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
}



