#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool dfs(int now, vector<vector<int>> &g, set<int> &used, vector<int> &route, vector<bool> &memo) {
    if (!memo[now]) return false;
    memo[now] = false;
    used.insert(now);
    route.push_back(now);

    for (int to : g[now]) {
        if (contain(used, to)) return true;
        bool ok = dfs(to, g, used, route, memo);
        if (ok) return true;
    }

    route.pop_back();
    used.erase(now);
    return false;
}

vector<int> min_cycle(int n, vector<vector<int>> &g, vector<int> &route) {
    map<int, int> used;
    rep(i, route.size()) used[route[i]] = i;

    rep(i, route.size()) {
        int now = route[i];
        int next = -1;

        for (int to : g[now]) {

            if (used.find(to) == used.end()) continue;
            int next_i = used[to];
            if (next_i > i) {
                // 次以降
                continue;
            }
            // 手前
            cmax(next, next_i);

        }

        if (next != -1) {
            // 切った。
            vector<int> ans;
            for (int j = next; j <= i; j++) ans.push_back(route[j]);
            return ans;
        }

    }

    return route;
}

int main() {
//    ifstream cin("C:\\Users\\riku\\Downloads\\case_30.txt");

    int n, m;
    cin >> n >> m;
    vector<P> v(m);
    for (P &p:v) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> g(n);
    for (P p: v) g[p.first].push_back(p.second);

    vector<bool> memo(n, true);
    vector<int> route = [&]() {
        rep(i, n) {
            set<int> used;
            vector<int> route;
            bool ok = dfs(i, g, used, route, memo);
            if (ok) {
                return route;
            }
        }
        return vector<int>(0);
    }();

    if (route.empty()) {
        cout << -1 << endl;
        ret();
    }
    route = min_cycle(n, g, route);


    vector<ll> costs(n, INF);
    vector<ll> pre(n, -1);

    queue<int> q;
    q.push(route.front());
    costs[route.front()] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ll next_cost = costs[now] + 1;
        for (int next : g[now]) {
            if (next_cost < costs[next]) {

                q.push(next);
                costs[next] = next_cost;
                pre[next] = now;
            }
        }
    }

    int now = route.back();
    vector<int> ans;
    while (now != route.front()) {
        ans.push_back(now);
        now = pre[now];
    }
    ans.push_back(now);

    cout << ans.size() << endl;
    for (int a : ans) cout << a + 1 << endl;


//    for (P p : v) {
//        if (find(ans.begin(), ans.end(), p.first) != ans.end() && find(ans.begin(), ans.end(), p.second) != ans.end()) {
//            cout << p.first + 1 << ' ' << p.second + 1 << endl;
//        }
//    }

}
