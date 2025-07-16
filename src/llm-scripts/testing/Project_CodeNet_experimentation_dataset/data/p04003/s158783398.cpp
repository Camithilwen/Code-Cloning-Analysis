#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

map<pii, vector<pair<pii, int>>> G;
map<pii, int> d;
set<int> company[100100];//company[i]:=駅iを通る会社
int N, M;

void dijkstra() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> que;
    d[pii(0, -1)] = 0;
    que.push(make_pair(0, pii(0, -1)));
    while (!que.empty()) {
        pair<int, pii> p = que.top();
        que.pop();
        pii v = p.second;
        if (d.count(v) && d[v] < p.first)continue;

        rep(i, G[v].size()) {
            pair<pii, int> edge = G[v][i];
            if (!d.count(edge.first) || d[edge.first] > d[v] + edge.second) {
                d[edge.first] = d[v] + edge.second;
                que.push(make_pair(d[edge.first], edge.first));
            }
        }
    }
}

signed main() {
    cin >> N >> M;
    rep(i, M) {
        int p, q, c;
        cin >> p >> q >> c;
        p--;
        q--;
        G[pii(p, c)].push_back(make_pair(pii(q, c), 0));
        G[pii(q, c)].push_back(make_pair(pii(p, c), 0));
        company[p].insert(c);
        company[q].insert(c);
    }
    rep(i, N) {
        for (int c:company[i]) {
            G[pii(i, c)].push_back(make_pair(pii(i, -1), 0));
            G[pii(i, -1)].push_back(make_pair(pii(i, c), 1));
        }
    }

    dijkstra();
    if (d.count(pii(N - 1, -1)))
        cout << d[pii(N - 1, -1)] << endl;
    else cout << -1 << endl;
    return 0;
}
