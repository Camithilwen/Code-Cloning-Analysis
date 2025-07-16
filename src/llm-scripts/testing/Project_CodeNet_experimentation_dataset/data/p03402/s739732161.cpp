#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B; cin >> A >> B;
    A--, B--;
    int h = 100, w = 100;
    vector<string> maze(h, string(w, '.'));
    rep(i, h/2) maze[i] = string(w, '#');

    bool flag = false;
    for (int i = 0; i < h / 2; i += 2) {
        for (int j = 0; j < w; j += 2) {
            if (A == 0) {
                break;
                flag = true;
            }
            maze[i][j] = '.';
            A--;
        }
        if (flag) break;
    }
    flag = false;
    for (int i = h / 2 + 1; i < h; i += 2) {
        for (int j = 0; j < w; j += 2) {
            if (B == 0) {
                break;
                flag = true;
            }
            maze[i][j] = '#';
            B--;
        }
        if (flag) break;
    }
    cout << h << ' ' << w << endl;
    rep(i, h) {
        cout << maze[i] << endl;
    }
    cout << endl;
    return 0;
}