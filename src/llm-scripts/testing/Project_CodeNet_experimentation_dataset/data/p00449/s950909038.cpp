#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

#define chmin(a,b) a=min(a,b)
#define rep(i,x) for(ll i=0;i<(x);++i)

const ll linf = 3e18;

ll cost[100][100];
ll d[100];
bool used[100];

ll N, K;

void dijkstra(ll s)
{
    fill_n(d, N, linf);
    fill_n(used, N, false);
    d[s] = 0;

    while (true) {
        ll v = -1;

        rep(u, N) {
            if (!used[u] && (v == -1 || d[v] > d[u])) v = u;
        }

        if (v == -1) break;
        used[v] = true;

        rep(u, N) {
            chmin(d[u], d[v] + cost[v][u]);
        }
    }
}

signed main()
{
    while (scanf("%lld %lld", &N, &K), N || K) {
        fill(cost[0], cost[N], linf);

        rep(i, K) {
            ll t; scanf("%lld", &t);
            if (t == 1) {
                ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c); a--; b--;
                chmin(cost[a][b], c);
                chmin(cost[b][a], c);
            } else {
                ll a, b; scanf("%lld %lld", &a, &b); a--; b--;
                dijkstra(a);
                printf("%lld\n", d[b] == linf ? -1 : d[b]);
            }
        }
    }
}