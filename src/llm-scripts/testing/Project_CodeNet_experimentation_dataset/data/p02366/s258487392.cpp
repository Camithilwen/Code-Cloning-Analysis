#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << p.first << " " << p.second;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

vector<vector<ll>> G;
vector<bool> used;
vector<ll> order;
ll next_order = 0;
vector<ll> ans;
void add_ans(ll v) {
    ans.pb(v);
}
ll dfs(ll v, ll prev) {
    ll res = order[v] = next_order++;
    bool is_articulation = false;
    ll d = 0;
    EACH(to, G[v]) {
        if (to == prev) continue;
        if (order[to] >= 0) {
            res = min(res, order[to]);
        }
        else {
            ll low = dfs(to, v);
            if (prev >= 0 && low >= order[v]) {
                is_articulation = true;
            }
            res = min(res, low);
            ++d;
        }
    }
    if (prev < 0 && d >= 2) is_articulation = true;
    if (is_articulation) add_ans(v);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> g(n);
    G.resize(n);
    REP(i, m) {
        ll a, b; cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    order.assign(n, -1);
    dfs(0, -1);
    sort(ALL(ans));
    EACH(a, ans) {
        cout << a << endl;
    }
}