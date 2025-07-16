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

// 借りました。
// https://kenkoooo.hatenablog.com/entry/2019/12/29/110321

const vector<vector<char>> s3 = vector<vector<char>>{
        {'a', 'a', '.',},
        {'.', '.', 'a',},
        {'.', '.', 'a',},
};

const vector<vector<char>> s4 = vector<vector<char>>{
        {'a', 'b', 'e', 'e'},
        {'a', 'b', 'f', 'f'},
        {'g', 'g', 'c', 'd'},
        {'h', 'h', 'c', 'd'},
};

const vector<vector<char>> s5 = {
        {'a', 'c', 'd', '.', '.'},
        {'a', 'c', 'd', '.', '.'},
        {'b', 'f', 'f', 'g', 'g'},
        {'b', '.', 'e', 'h', 'h'},
        {'i', 'i', 'e', 'j', 'j'},
};

const vector<vector<char>> s6 = {
        {'a', 'd', 'g', 'g', '.', '.'},
        {'a', 'd', 'h', 'h', '.', '.'},
        {'b', 'e', 'i', 'i', '.', '.'},
        {'b', 'e', '.', '.', 'j', 'j'},
        {'c', 'f', '.', '.', 'k', 'k'},
        {'c', 'f', '.', '.', 'l', 'l'},
};

const vector<vector<char>> s7 = {
        {'a', 'd', 'f', '.', '.', '.', '.'},
        {'a', 'd', 'f', '.', '.', '.', '.'},
        {'b', 'e', 'g', '.', '.', '.', '.'},
        {'b', 'e', 'g', '.', '.', '.', '.'},
        {'c', '.', '.', 'h', 'h', 'i', 'i'},
        {'c', '.', '.', 'j', 'j', 'k', 'k'},
        {'.', 'l', 'l', 'm', 'm', 'n', 'n'},
};

P solve(int n) {
    rep(i, 1000) {
        int x = i;
        int y = n - (4 * x);

        if (y == 5) {
            return {x, y};
        }

        if (y == 6) {
            return {x, y};
        }

        if (y == 7) {
            return {x, y};
        }

        if (y == 0) {
            return {x, y};
        }
    }

    __throw_runtime_error("konaide");
}

void copy_print(vector<vector<char>> &ans, int n, const vector<vector<char>> &from, int sy, int sx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[sy + i][sx + j] = from[i][j];
        }
    }
}

void print(const vector<vector<char>> &ans) {
    for (auto &line: ans) {
        for (char e : line) cout << e;
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << -1 << endl;
        ret();
    }

    if (n == 3) {
        print(s3);
        ret();
    }

    P p = solve(n);

    vector<vector<char>> ans(n, vector<char>(n, '.'));

    rep(i, p.first) {
        int sy = 4 * i;
        int sx = 4 * i;

        copy_print(ans, 4, s4, sy, sx);
    }

    if (p.second == 5) {
        int sy = p.first * 4;
        int sx = p.first * 4;
        copy_print(ans, 5, s5, sy, sx);
    }

    if (p.second == 6) {
        int sy = p.first * 4;
        int sx = p.first * 4;
        copy_print(ans, 6, s6, sy, sx);
    }

    if (p.second == 7) {
        int sy = p.first * 4;
        int sx = p.first * 4;
        copy_print(ans, 7, s7, sy, sx);
    }

    print(ans);

}
