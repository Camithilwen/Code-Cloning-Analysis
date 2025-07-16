#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <map>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

class Direct_Graph {
    public:
    struct Edge { 
        int to; int cost;
    };
    std::vector<std::vector<Edge>> G;
    int node_num;
    Direct_Graph() {}
    Direct_Graph(const int node_num_in) {
        node_num = node_num_in;
        G.resize(node_num);
    }
    void add_edge(const int from, const int to, const int cost) {
        Edge edge; edge.to = to; edge.cost = cost;
        G[from].push_back(edge);
    }
    void add_edge_both(const int node1, const int node2, const int cost) {
        add_edge(node1, node2, cost);
        add_edge(node2, node1, cost);
    }

    std::vector<int> Dijkstra(int s, const int dist_inf) {
        std::vector<int> dist; dist.resize(node_num);
        for (int i = 0; i < dist.size(); i++) {
            dist[i] = dist_inf;
        }
        typedef std::pair<int, int> Pair;

        std::priority_queue <Pair, std::vector<Pair>, std::greater<Pair>> que;
        dist[s] = 0;
        que.push(Pair(0, s));

        while (!que.empty()) {
            Pair pair = que.top(); que.pop();
            int v = pair.second;
            if (dist[v] < pair.first) { continue; }
            for (Edge edge : G[v]) {
                if (dist[v] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[v] + edge.cost;
                    que.push(Pair(dist[edge.to], edge.to));
                }
            }
        }

        return dist;
    }
};

const int MAX_N = 100050;
const int MAX_M = 200050;

int N, M;
int p[MAX_M], q[MAX_M], c[MAX_M];

Direct_Graph graph = Direct_Graph(MAX_N + MAX_M * 2);

std::map<std::pair<int, int>, int> mp;

int main(int argc, char **argv) {
    std::cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        std::cin >> p[i] >> q[i] >> c[i];
    }
    
    int idx = N + 1;
    for (int i = 1; i <= M; i++) {
        if (mp.find(std::pair<int, int>({p[i], c[i]})) == mp.end()) {
            mp[std::pair<int, int>({p[i], c[i]})] = idx;
            graph.add_edge(p[i], idx, 1);
            graph.add_edge(idx, p[i], 0);
            idx++;
        }
        if (mp.find(std::pair<int, int>({q[i], c[i]})) == mp.end()) {
            mp[std::pair<int, int>({q[i], c[i]})] = idx;
            graph.add_edge(q[i], idx, 1);
            graph.add_edge(idx, q[i], 0);
            idx++;
        }
        int node_p = mp[std::pair<int, int>({p[i], c[i]})];
        int node_q = mp[std::pair<int, int>({q[i], c[i]})];

        //graph.add_edge_both(p[i], q[i], 1);
        //graph.add_edge_both(p[i], node_q, 1);
        //graph.add_edge_both(node_p, q[i], 1);
        graph.add_edge_both(node_p, node_q, 0);
    }

    std::vector<int> dist = graph.Dijkstra(1, MAX_M * 2);
    int ret = dist[N];

    /*
    for (int i = 1; i <= M; i++) {
        if (p[i] == N) {
            ret = std::min(ret, dist[mp[std::pair<int, int>({p[i], c[i]})]]);
        } else if (q[i] == N) {
            ret = std::min(ret, dist[mp[std::pair<int, int>({q[i], c[i]})]]);
        }
    }
    */

    if (ret < MAX_M * 2) {
        std::cout << ret << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    
    return 0;
}
