#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;


class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }
};


int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    UnionFind uf(h * w);

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    rep(y, h) {
        rep(x, w) {
            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;
                if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
                if (grid[y][x] != grid[ny][nx]) uf.connect(to_id(y, x), to_id(ny, nx));
            }
        }
    }

    UnionFind uf2(h * w);


    rep(y, h) {
        rep(x, w) {
            if (grid[y][x] != '#') continue;
            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;
                if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
                if (grid[ny][nx] != '.')continue;

                for (Direction e : directions) {
                    int nny = ny + e.y;
                    int nnx = nx + e.x;
                    if (nny < 0 || h <= nny || nnx < 0 || w <= nnx) continue;
                    if (grid[nny][nnx] != '#')continue;

                    uf2.connect(to_id(y, x), to_id(nny, nnx));
                }
            }
        }
    }

    ll ans = 0;
    rep(y, h) {
        rep(x, w) {
            if (grid[y][x] != '#') continue;
            ll now = uf.size(to_id(y, x)) - uf2.size(to_id(y, x));
//            cout << uf.size(to_id(y, x)) << ' ' << uf2.size(to_id(y, x)) << ' ' << now << endl;
            ans += now;

        }
    }
    cout << ans << endl;
}
