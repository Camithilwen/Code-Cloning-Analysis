#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

struct edge {
    ll to, cost;
};

int V;
vector<edge> G[1000000];
vector<edge> G2[1000000];
ll d[1000000];

void addedge(int st, int ed, ll co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

void addedge2(int st, int ed, ll co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G2[st].push_back(e);
}

ll ptlab[3000000];
map<plglg, ll> mp;

void BFS01(int n) {
    fill(d, d + V, llmax);
    deque<int> que;
    d[n] = 0;
    que.push_front(n);
    while (que.size() > 0) {
        int base = que.front();
        que.pop_front();
        int s = G[base].size();
        for (int i = 0; i < s; i++) {
            edge e = G[base][i];
            if (e.cost == 1 && d[e.to] > d[base] + 1) {
                d[e.to] = d[base] + 1;
                que.push_back(e.to);
            } else if (e.cost == 0 && d[e.to] > d[base]) {
                d[e.to] = d[base];
                que.push_front(e.to);
            }
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    ll p[M], q[M], c[M];
    REP(i, 0, M) {
        cin >> p[i] >> q[i] >> c[i];
        addedge2(p[i] - 1, q[i] - 1, c[i]);
        addedge2(q[i] - 1, p[i] - 1, c[i]);
    }
    REP(i, 0, N) {
        mp[plglg(i, -1)] = i;
        ptlab[i] = i;
    }
    ll pt = N;
    REP(i, 0, N) {
        REP(j, 0, G2[i].size()) {
            edge e = G2[i][j];
            if (mp.count(plglg(e.to, e.cost)) == 0) {
                mp[plglg(e.to, e.cost)] = pt;
                ptlab[pt] = e.to;
                pt++;
            }
        }
    }
    V = pt;
    REP(i, N, pt) {
        ll label = ptlab[i];
        addedge(label, i, 1); 
    }
    REP(i, 0, N) {
        REP(j, 0, G2[i].size()) {
            edge e = G2[i][j];
            if (mp.count(plglg(i, e.cost)) == 1) {
                addedge(mp[plglg(i, e.cost)], mp[plglg(e.to, e.cost)], 0);
            }
            addedge(mp[plglg(e.to, e.cost)], ptlab[e.to], 0);
        }
    }
    BFS01(0);
    ll ans = d[N - 1];
    if (ans != llmax) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
