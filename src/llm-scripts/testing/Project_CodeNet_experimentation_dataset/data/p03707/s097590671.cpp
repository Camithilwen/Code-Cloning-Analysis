#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
template<typename T>
class Sum2d {
    vector<vector<T> > vv;
    unsigned xSize{};
    unsigned ySize{};
public:
    Sum2d(unsigned xSize, unsigned ySize) {
        vector<vector<T> > vv(xSize + 2, vector<T>(ySize + 2));
        this->vv = vv;
        this->xSize = xSize + 2;
        this->ySize = ySize + 2;
    }

    void add(int x, int y, T value) {
        x++;
        y++;
        this->vv[x][y] += value;
    }

    void set_sum() {
        for (int i = 0; i < xSize - 1; i++) {
            for (int j = 0; j < ySize; j++) {
                this->vv[i + 1][j] += vv[i][j];
            }
        }
        for (int i = 0; i < xSize; i++) {
            for (int j = 0; j < ySize - 1; j++) {
                this->vv[i][j + 1] += vv[i][j];
            }
        }
    }

    //[sx,tx],[sy,ty]の範囲を求めるZE
    T calc(int sx, int sy, int tx, int ty) {
        tx++;
        ty++;
        return this->vv[tx][ty] + this->vv[sx][sy] - this->vv[tx][sy] - this->vv[sx][ty];
    }
};

class Solve {
public:
    void solve() {
        Int N, M, Q;
        cin >> N >> M >> Q;
        vector<string> S(N);
        Sum2d<int> V(2 * N, 2 * M), E(2 * N, 2 * M);
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
            for (int j = 0; j < M; ++j) {
                if (S[i][j] == '1') {
                    V.add(2 * i, 2 * j, 1);
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j + 1 < M; ++j) {
                if (S[i][j] == '1' && S[i][j + 1] == '1') {
                    E.add(2 * i, 2 * j + 1, 1);
                }
            }
        }
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i + 1 < N; ++i) {
                if (S[i][j] == '1' && S[i + 1][j] == '1') {
                    E.add(2 * i + 1, 2 * j, 1);
                }
            }
        }
        V.set_sum();
        E.set_sum();

        for (int i = 0; i < Q; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            int r1 = 2 * x1;
            int c1 = 2 * y1;
            int r2 = 2 * x2;
            int c2 = 2 * y2;
            Int v1 = V.calc(r1, c1, r2, c2);
            Int e1 = E.calc(r1, c1, r2, c2);
            Int tmp = V.calc(r1, c1, r2, c2) - E.calc(r1, c1, r2, c2);
            cout << tmp << endl;
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
