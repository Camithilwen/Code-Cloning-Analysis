#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 100000;
int n, m;
vi a(maxn);
vi table(maxn);

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

int lds() {
    table.resize(n);
    REP(i, n) {
        table[i] = -1;
    }
    REP(i, n) {
        auto iter = upper_bound(table.begin(), table.end(), a[i], [](const int& a, const int& b) { return a > b; });
        *iter = a[i];
    }
    auto iter = lower_bound(table.begin(), table.end(), -1, [](const int& a, const int& b) { return a > b; });
    return (int) (iter - table.begin());
}

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    // https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D
    cin >> n;
    REP(i, n) {
        cin >> a[i];
    }

    int ret = lds();
    cout << std::fixed << std::setprecision(10) << ret << "\n";
}