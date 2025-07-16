#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 4 * N + 5;

int head[N], nxt[M], to[M], typ[M], ne, n;

void init(){
    ne = 0;
    memset(head, -1, n * sizeof head[0]);
}

void addEdge(int f, int t, int ty){
    to[ne] = t;
    typ[ne] = ty;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int a, int b, int ty){
    addEdge(a, b, ty);
    addEdge(b, a, ty);
}

struct state{
    int dis;
    set<int> typs;
};

state node[N];

bool inQ[N];

int dij(){
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);

    for(int i = 0 ; i < n ; ++i)
        node[i].dis = (int)1e9;

    node[0].dis = 0;
    inQ[0] = true;

    int cst, v;

    while(pq.size()){
        auto top = pq.top();
        pq.pop();

        int u = top.second;
        int d = top.first;
        inQ[u] = false;


        if(node[u].dis < d)continue;

        for(int e = head[u] ; ~e ; e = nxt[e]){
            v = to[e];
            cst = (node[u].typs.find(typ[e]) == node[u].typs.end());

            if(node[u].dis + cst < node[v].dis){
                inQ[v] = true;
                node[v] = {node[u].dis + cst, {typ[e]}};
                pq.emplace(node[v].dis, v);
            }

            else if(node[u].dis + cst == node[v].dis){
                if(node[v].typs.find(typ[e]) != node[v].typs.end())continue;
                node[v].typs.emplace(typ[e]);
                if(!inQ[v])
                    pq.emplace(node[v].dis, v), inQ[v] = true;
            }
        }

    }

    if(node[n - 1].dis > n)
        node[n - 1].dis = -1;
    return node[n - 1].dis;
}

int main(){
    IO;
    int m;
    scanf("%d %d", &n, &m);
    init();
    while(m--){
        int u, v, ty;
        scanf("%d %d %d", &u, &v, &ty);
        addBiEdge(--u, --v, ty);
    }
    printf("%d\n", dij());
}