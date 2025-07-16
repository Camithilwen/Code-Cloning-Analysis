#include <iostream>
#include <vector>
#include <stack>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void makeStackRecur(vector<vector<int> > &g, int u, stack<int> &out, vector<bool> &seen) {
    seen[u] = true;
    for(int v: g[u])
        if (! seen[v])
            makeStackRecur(g, v, out, seen);
    out.push(u);
}

void makeStack(vector<vector<int> > &g, int u, vector<bool> &seen, stack<int> &vStack) {
    makeStackRecur(g, u, vStack, seen);
}
void getConnectedCompRecur(vector<int> &rootGroup, vector<vector<int> > &invGraph, int u, int root) {
    if (rootGroup[u] == -1) {
        rootGroup[u] = root;
        for(int v: invGraph[u])
            getConnectedCompRecur(rootGroup, invGraph, v, root);
    }
}

void getConnectedComp(vector<int> &rootGroup, vector<vector<int> > &invGraph, stack<int> &vStack) {
    while (! vStack.empty()) {
        int u = vStack.top();
        vStack.pop();
        getConnectedCompRecur(rootGroup, invGraph, u, u);
    }
}
int main () {
    int V, E;
    cin >> V >> E;

    vector<vector<int> > graph(V);
    vector<vector<int> > invGraph(V);
    vector<bool> seen(V, false);
    vector<int> rootGroup(V, -1);

    FOR(i,E) {
        int s, t;
        cin >> s >> t;

        graph[s].push_back(t);
        invGraph[t].push_back(s);
    }

    stack<int> vStack;
    FOR(i, V)
        if (! seen[i]) makeStack(graph, i, seen, vStack);

    FOR(i, V)
        if (rootGroup[i] == -1) getConnectedComp(rootGroup, invGraph, vStack);

    int Q;
    cin >> Q;
    FOR(i,Q) {
        int f, t;
        cin >> f >> t;
        cout << (rootGroup[f] == rootGroup[t]) << endl;
    }
}

