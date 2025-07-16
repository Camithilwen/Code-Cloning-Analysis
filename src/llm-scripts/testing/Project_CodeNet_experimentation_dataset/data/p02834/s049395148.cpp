#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

ll CA[100005];
ll CT[100005];
Vertex V[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, T;
    cin >> N >> T >> A;
    T--;
    A--;
    REP(i, N) {
        CT[i] = CA[i] = INF;
    }
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    {
        queue<pll> q;
        q.push(pll(A, 0));
        CA[A] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            for (auto n : V[t.first].node) {
                if (CA[n] <= cost)
                    continue;
                CA[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }
    {
        queue<pll> q;
        q.push(pll(T, 0));
        CT[T] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            for (auto n: V[t.first].node) {
                if (CT[n] <= cost)
                    continue;
                CT[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }

    ll ans = 0;
    REP(i, N) {
        if (CA[i] >= CT[i])
            ans = std::max(ans, CA[i] - 1);
    }
    cout << ans << endl;
    return 0;
}