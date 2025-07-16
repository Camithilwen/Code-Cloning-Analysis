#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y) {
        sum[x][y]++;
    }

    ll get(ll x, ll y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (x == sum.size() || y == sum[x].size()) {
            return 0;
        }
        return sum[x][y];
    }

    void setUp() {
        for (ll x = 0; x < sum.size(); x++) {
            for (ll y = 0; y < sum[x].size(); y++) {
                sum[x][y] += get(x - 1, y) + get(x, y - 1) - get(x - 1, y - 1);
            }
        }
    }

    ll getSum(ll xs, ll ys, ll xe, ll ye) {
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    MatrixSum b(h, w), bv(h, w), bh(h, w);

    rep(y, h) rep(x, w) if (grid[y][x] == '1') b.add(y, x);
    rep(y, h) rep(x, w - 1) if (grid[y][x] == '1' && grid[y][x + 1] == '1') bh.add(y, x);
    rep(y, h - 1) rep(x, w) if (grid[y][x] == '1' && grid[y + 1][x] == '1') bv.add(y, x);

    b.setUp();
    bv.setUp();
    bh.setUp();
    rep(_, q) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        y2--;
        x2--;

        int bc = b.getSum(y1, x1, y2, x2);
        int bvc = y1 == y2 ? 0 : bv.getSum(y1, x1, y2 - 1, x2);
        int bhc = x1 == x2 ? 0 : bh.getSum(y1, x1, y2, x2 - 1);

        int ans = bc - bvc - bhc;

        cout << ans << endl;
    }

}
