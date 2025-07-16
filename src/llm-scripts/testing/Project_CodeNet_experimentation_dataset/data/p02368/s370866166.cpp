#include <iostream>

#include <functional> // std::function
#include <vector> // std::vector

struct edge {
    using weight_type = size_t;

    size_t to;

    edge(size_t to) : to(to) { }

    size_t cost() { return 1; }
};

struct graph {
    using edge_type = edge;

    const bool is_directed;
    const size_t count_vertices;
    std::vector<edge> *edges;

    graph(size_t count_vertices, bool is_directed = true) : count_vertices(count_vertices), is_directed(is_directed) {
        edges = new std::vector<edge>[count_vertices];
    }

    ~graph() {
        delete [] edges;
    }

    void make_edge(size_t from, size_t to) {
        edges[from].push_back(edge(to));
        if (!is_directed) {
            edges[to].push_back(edge(from));
        }
    }
};

graph opposite_graph(const graph &g) {
    size_t n = g.count_vertices;
    graph op_g(n);
    for (size_t u = 0; u < n; ++u) {
        for (const edge &e: g.edges[u]) {
            size_t v = e.to;
            op_g.make_edge(v, u);
        }
    }
    return op_g;
}

/*
template <class Graph>
std::vector<size_t> post_order_traversal(const Graph &g, size_t root) {
    using Edge = typename Graph::edge_type;

    size_t n = g.count_vertices;
    std::vector<size_t> order;
    std::vector<bool> used(n, false);
    std::function<void(size_t)> dfs = [&](size_t u) {
        printf("start node %d\n", u);
        used[u] = true;
        for (const Edge &e: g.edges[u]) {
            size_t v = e.to;
            if (!used[v]) {
                dfs(v);
            }
        }
        printf("end node %d\n", u);
        order.push_back(u);
    };
    dfs(root);
    return order;
}
*/

template <class Graph>
std::vector<size_t> strongly_connected_component(const Graph &g) {
    using Edge = typename Graph::edge_type;

    size_t n = g.count_vertices;
    std::vector<bool> used(n, false);

    std::vector<size_t> post_order;
    std::function<void(size_t)> post_order_traversal = [&](size_t u) {
        used[u] = true;
        for (const Edge &e: g.edges[u]) {
            size_t v = e.to;
            if (!used[v]) {
                post_order_traversal(v);
            }
        }
        post_order.push_back(u);
    };
    for (size_t u = 0; u < n; ++u) {
        if (!used[u]) {
            post_order_traversal(u);
        }
    }

    Graph op_g = opposite_graph(g);
    std::vector<size_t> component(n, 123);
    std::function<void(size_t, size_t)> dfs = [&](size_t u, size_t component_index) {
        component[u] = component_index;
        used[u] = true;
        for (const Edge &e: op_g.edges[u]) {
            size_t v = e.to;
            if (!used[v]) {
                dfs(v, component_index);
            }
        }
    };
    size_t count_components = 0;
    fill(used.begin(), used.end(), false);
    for (int i = n - 1; i >= 0; --i) {
        size_t u = post_order[i];
        if (!used[u]) {
            dfs(u, count_components++);
        }
    }
    return component;
}

int main() {
    using namespace std;

    int V, E;
    cin >> V >> E;
    graph g(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.make_edge(u, v);
    }
    auto component = strongly_connected_component(g);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << (component[u] == component[v]) << '\n';
    }
    cout << flush;
    return 0;
}
