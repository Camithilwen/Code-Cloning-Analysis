#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > graph;
vector<int> color;
graph G;

bool dfs(int s, int c) {
    color[s] = c;
    for (int i = 0; i < G[s].size(); i++) {
        int v = G[s][i];
        if (color[v] == c)
            return false;
        else if (color[v] == 0 && !dfs(v, -c))
            return false;
    }
    return true;
}

int main() {
    long long n, m;   cin >> n >> m;
    G = graph(n);
    color.resize(n);
    for (int i = 0; i < n; i++)
        color[i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    if (dfs(0, 1)) {
        long long B = 0, W = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == 1)
                B++;
            else if (color[i] == -1)
                W++;
            
        }
        cout << B * W - m << endl;
    }
    else {
        cout << ((n*(n-1))/2) - m << endl;
    }

    return 0;
}