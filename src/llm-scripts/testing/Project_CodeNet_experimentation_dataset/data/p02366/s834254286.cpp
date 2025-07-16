#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

using Weight=long long;
static const Weight INF=1LL<<57;

struct Edge {
    size_t src, dst;
    Weight weight;
    Edge() {}
    Edge(size_t src, size_t dst, Weight weight=1):
        src(src), dst(dst), weight(weight)
    {}
};

bool operator<(const Edge &e, const Edge &f) {
    if (e.weight != f.weight) {
        return e.weight > f.weight;
    } else {
        return e.src!=f.src? e.src<f.src : e.dst<f.dst;
    }
}

using Edges=vector<Edge>;
using Vertex=vector<Edge>;
using Graph=vector<Vertex>;

void join(Graph &g, size_t s, size_t d, Weight w=1) {
    // non-directed
    g[s].push_back(Edge(s, d, w));
    g[d].push_back(Edge(d, s, w));
}

void connect(Graph &g, size_t s, size_t d, Weight w=1) {
    // directed
    g[s].push_back(Edge(s, d, w));
}

void visit(
    const Graph &g, size_t v, size_t u, set<size_t> &artpoint,
    vector<size_t> &num, vector<size_t> &low, int &time
) {
    low[v] = num[v] = ++time;
    for (const Edge &e: g[v]) {
        size_t w=e.dst;
        if (!num[w]) {
            visit(g, w, v, artpoint, num, low, time);
            low[v] = min(low[v], low[w]);

            if (num[v]==1? num[w]!=2 : low[w]>=num[v])
                artpoint.insert(v);

        } else {
            low[v] = min(low[v], num[w]);
        }
    }
}

set<size_t> get_artpoint(const Graph &g) {
    const size_t V=g.size();

    vector<size_t> low(V), num(V);
    set<size_t> artpoint;
    for (size_t u=0; u<V; ++u) if (!num[u]) {
        int time=0;
        visit(g, u, -1, artpoint, num, low, time);
    }

    return artpoint;
}

int main() {
    size_t V, E;
    scanf("%zu %zu", &V, &E);

    Graph g(V);
    for (size_t i=0; i<E; ++i) {
        size_t s, t;
        scanf("%zu %zu", &s, &t);

        join(g, s, t);
    }

    set<size_t> artpoint=get_artpoint(g);

    for (size_t v: artpoint)
        printf("%zu\n", v);

    return 0;
}