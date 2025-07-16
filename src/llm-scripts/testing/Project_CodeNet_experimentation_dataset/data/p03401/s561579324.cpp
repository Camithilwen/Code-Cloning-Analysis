#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep_r(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(),x.end()
#define resize(x, n) x.resize(n)
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ll MAX = 100000;
struct edge {
    ll from, to, weight;
    edge(ll f, ll t, ll w) : from(f), to(t), weight(w) { }
};
vector<vector<edge>> edges;
vector<vector<ll>> graph;
vector<bool> visited;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll n, sum;
vl a;

ll cost(ll i) {
    return sum - abs(a[i-1]-a[i]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    resize(a, n+2);
    rep(i, n+2) {
        if (i == 0 || i == n+1) a[i] = 0;
        else cin >> a[i];
        if (i > 0) sum += abs(a[i-1]-a[i]);
    }
    rep(i, n+1) {
        if (i == 0) continue;
        printf("%ld\n", cost(i));
    }
}