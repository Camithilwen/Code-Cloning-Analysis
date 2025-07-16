#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for(int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 0x3b9aca07;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

vector<int> par;

int root(int x) {
    if (par[x] < 0) return x;
    return par[x] = root(par[x]);
}

int size(int x) {
    return -par[root(x)];
}

void merge(int x, int y) {
    if (size(x) < size(y)) swap(x, y);
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] += par[ry];
    par[ry] = rx;
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

    ll n, m; cin >> n >> m;

    par.assign(n * 2, -1);
    
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a, --b;
		merge(a, b + n);
		merge(b, a + n);
    }

    if (root(0) != root(n)) {
        // 二部グラフの左側*右側
        ll cnt = 0;
        rep(i, 0, n)
            if (root(0) == root(i)) ++cnt;
        cout << cnt * (n - cnt) - m << endl;
    }
    else {
        cout << n * (n - 1) / 2 - m << endl;
    }

	return 0;
}
