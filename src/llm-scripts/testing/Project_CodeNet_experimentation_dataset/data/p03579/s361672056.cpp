#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


vector<ll> bfs(int n, vector<vector<int>> &g) {

    vector<ll> costs(n, INF);
    costs[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (int to  : g[from]) {
            if (costs[to] != INF) continue;
            costs[to] = costs[from] + 1;
            q.push(to);
        }
    }
    return costs;
}


bool bfs2(int n, vector<vector<int>> &g) {
    vector<ll> costs(n, INF);
    costs[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {

        int from = q.front();
        q.pop();
        for (int to  : g[from]) {

            ll current_cost = costs[to];
            ll next_cost = costs[from] + 1;

            if (current_cost != INF) {
                if (current_cost % 2 != next_cost % 2) return false;
                continue;
            }
            costs[to] = next_cost;
            q.push(to);
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> v(m);
    for (P &p : v) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> g(n);
    for (P p: v) g[p.first].push_back(p.second);
    for (P p: v) g[p.second].push_back(p.first);

    vector<ll> costs = bfs(n, g);
    bool is_2 = bfs2(n, g);

    if (is_2) {
        ll a = 0;
        for (ll c : costs) if (c % 2 == 0) a++;
        ll b = n - a;
        ll all = a * b;
        ll ans = all - m;
        cout << ans << endl;
        ret();
    }

    ll all = ll(n) * (n - 1) / 2;
    ll ans = all - m;
    cout << ans << endl;
}