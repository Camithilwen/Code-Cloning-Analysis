#include <bits/stdc++.h>
using namespace std;

#define int long long
#define itn int
#define For(i, a, b) for (int i = (a); i <= static_cast<int>(b); i++)
#define Forr(i, a, b) for (int i = (a); i >= static_cast<int>(b); i--)
#define rep(i, n) For(i, 0, n - 1)
#define repall(i, arr) for (auto& i : (arr))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'
#define dump2(x, y) \
    cerr << #x << " = " << (x) << " " << #y << " = " << (y) << '\n'
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
constexpr int MOD = 1e9 + 7;

template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;
const int INF = LLONG_MAX / 2;
using P = pair<int, int>;
using vec = vector<int>;
template <typename T>
using mat = vector<vector<T>>;

// clang-format off
template <typename T1, typename T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& p) { return stream << p.first << "," << p.second; }
template <typename T>
void print(const vector<T> vec) { rep (i, vec.size() - 1) cout << vec[i] << ' '; cout << vec[vec.size() - 1] << '\n'; }
template <typename Arg>
void print(const Arg arg) { cout << arg << '\n'; }
template <typename Head, typename... Args>
void print(const Head head, const Args... args) { cout << head << " "; print(args...); }
template <typename T, typename U>
void init(vector<T>& v, vector<U>& w) { rep (i, v.size()) cin >> v[i] >> w[i]; }
template <typename T>
void init(vector<T>& v) { rep (i, v.size()) cin >> v[i]; }
template <typename T>
T sum_(vector<T> vec, T init = 0) { return std::accumulate(all(vec), T(init)); }
template<typename T>
bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<typename T>
bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <typename T>
int index(const T& vec, const typename T::iterator it) { return distance(vec.begin(), it); }
template <typename T = int>
mat<T> mmat(int n, int m=0) { return mat<T>(n, vector<T>(m)); }
template <typename T = int>
vector<T> ivec(int n) { vector<T> v(n); init(v); return v; }
// clang-format on

void yn(bool tf) { print(tf ? "Yes" : "No"); }
void YN(bool tf) { print(tf ? "YES" : "NO"); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// -------------------------------------------------------------------
// sort 1 2 3 4
// pqr 1 2 3 must impl >

signed main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    a--, b--;
    mat<char> grid = mmat<char>(100, 100);
    rep (i, 50)
        rep (j, 100)
            grid[i][j] = '.';
    rep (i, 50)
        rep (j, 100)
            grid[i + 50][j] = '#';

    rep (i, a) {
        int row = i / 50 * 2 + 51;
        int col = (i % 50) * 2;
        grid[row][col] = '.';
    }
    rep (i, b) {
        int row = i / 50 * 2;
        int col = (i % 50) * 2;
        grid[row][col] = '#';
    }

    print(100, 100);
    rep (i, 100) {
        rep (j, 100)
            cout << grid[i][j];
        cout << endl;
    }

    return 0;
}
