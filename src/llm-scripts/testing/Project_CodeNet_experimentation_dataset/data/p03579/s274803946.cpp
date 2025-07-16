#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

bool dual = 1;
int d[100020] = {};
vector<int> G[100010];
vector<bool> vis;

void dfs(int k, int dep) {
    vis[k] = 1;
    if (d[k] == 0) {
        if (dep % 2) d[k] = 1;
        else d[k] = 2;
    }
    for (auto &i : G[k]) {
        if (!vis[i]) {
            dfs(i, dep + 1);
        }
        else if (d[i] % 2 == dep % 2) {
            dual = 0;
            return;
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    int x[m], y[m];
    vis.assign(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--;  y[i]--;
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }

    dfs(0, 0);
    if (dual) {
        ll p = 0, q = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == 1) p++;
            else q++;
        }
        ll ans = p * q;
        for (int i = 0; i < m; i++) {
            if (d[x[i]] != d[y[i]]) ans--;
        }
        cout << ans << endl;
    }
    else {
        cerr << 0 << endl;
        cout << n * (n - 1) / 2 - m << endl;
    }
}