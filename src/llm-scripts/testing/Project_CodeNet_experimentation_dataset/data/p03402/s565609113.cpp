#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int a, b; cin >> a >> b;

    vector<string> s(100, string(100, '#'));
    rep(i, 50) rep(j, 100) s[i][j] = '.';

    int cnt = 0;
    for (int i = 0; i < 50; i += 2) {
        if (cnt == b - 1) break;
        for (int j = 0; j < 100; j += 2) {
            if (cnt == b - 1) break;
            s[i][j] = '#';
            cnt++;
        }
    }

    cnt = 0;
    for (int i = 51; i < 100; i += 2) {
        if (cnt == a - 1) break;
        for (int j = 0; j < 100; j += 2) {
            if (cnt == a - 1) break;
            s[i][j] = '.';
            cnt++;
        }
    }

    printf("100 100\n");
    for (auto &line: s) cout << line << endl;

}
