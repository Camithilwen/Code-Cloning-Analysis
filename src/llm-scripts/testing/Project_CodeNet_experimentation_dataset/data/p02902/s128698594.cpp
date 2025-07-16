#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >
#define endl '\n'

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    VEC(VEC(int)) Edges(N);
    FOR(i, 0, M) {
        int u, v;
        cin >> u >> v;
        Edges[u - 1].push_back(v - 1);
    }

    VEC(VEC(int)) Reach(N, VEC(int)(N, 10000));
    FOR(i, 0, N) {
        VEC(int)& Bfs = Reach[i];
        queue<int> q;
        q.push(i);

        while (q.size()) {
            int v = q.front();
            q.pop();
            for (int u : Edges[v])
                if (Bfs[u] >= 10000) {
                    q.push(u);
                    int dist = v == i ? 0 : Bfs[v];
                    Bfs[u] = 1 + dist;
                }
        }
    }

    VEC(int) cycle(10000, 0);
    FOR(i, 0, N)
        if (cycle.size() >= 10000 || Reach[i][i] < cycle.size()) {
            cycle.clear();
            int node = i, dist = Reach[i][i];
            while (dist--) {
                cycle.push_back(node);
                for (int next : Edges[node]) {
                    if (next == i) {
                        goto done;
                    }

                    if (Reach[next][i] == dist) {
                        node = next;
                        break;
                    }
                }
            }

done:
            continue;
        }

    if (cycle.size() >= 10000) {
        cout << -1 << endl;
        return 0;
    }

    cout << cycle.size() << endl;
    for (int v : cycle)
        cout << (v + 1) << endl;
    return 0;
};