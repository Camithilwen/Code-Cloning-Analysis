#include<iostream>
#include<algorithm>
using namespace std;

int *p,*rank;
int V,E,sum=0,n=0;
struct edge {
    int u;
    int v;
    int cost;
};
edge *e;
bool operator<(const edge& x, const edge& y) {
        return x.cost < y .cost;
}

void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
}

void link(int x, int y) {
    if(rank[x] > rank[y]) p[y] = x;
    else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y] = rank[y]+1;
    }
}

int findSet(int x) {
    if(x != p[x]) p[x] = findSet(p[x]);
    return p[x];
}

void unit(int x, int y) {
    link(findSet(x), findSet(y));
}

int kruskal() {
    sort(e, e+E);
    for(int i=0; n != V-1; i++) {
        if(findSet(e[i].u) != findSet(e[i].v)) {
            unit(e[i].u,e[i].v);
            sum += e[i].cost;  n++;
        }
    }
}

int main() {
    int s,t,w;
    cin >> V >> E;
    p = new int[V];
    rank = new int[V];
    e = new edge[E];
    for(int i=0; i<V; i++) makeSet(i);
    for(int i=0; i<E; i++) {
        cin >> s >>t >> w;
        edge a = {s,t,w};
        e[i] = a;
    }
    kruskal();
    cout << sum << endl;
    delete[] p,rank,e;

    return 0;
}

